#! /usr/bin/env python
# $NetBSD: distlint.py,v 1.1 2022/09/04 21:38:48 rillig Exp $

import argparse
import os
import re
from pathlib import Path
from typing import NamedTuple, List, Optional, Set, Dict
from logging import debug


pkg_info = '@PREFIX@/sbin/pkg_info'


class DistinfoEntry(NamedTuple):
    """
    One distfile from a distinfo file, including its hashes.
    """
    distfile: Path
    hashes: Dict[str, str]

    loc_pkgsrc_dir: Path
    loc_distinfo: Path


class BinaryPackage(NamedTuple):
    """
    A file containing a binary package for a particular platform.
    """

    file: Path
    pkgname: str
    build_info: Dict[str, str]
    distinfo_entries: List[DistinfoEntry]

    def load_build_info(self) -> Dict[str, str]:
        if len(self.build_info) > 0:
            return self.build_info

        slash_file = str(self.file).replace('\\', '/')
        for line in os.popen(f'{pkg_info} -q -B "{slash_file}"').readlines():
            line = line.rstrip()
            if line == '':
                continue
            key, value = line.split('=', 1)
            self.build_info[key] = value

        return self.build_info

    def no_src_on_ftp(self) -> str:
        return self.load_build_info().get('NO_SRC_ON_FTP', '')

    def license(self) -> str:
        return self.load_build_info().get('LICENSE', '')

    def load_distinfo_entries(self, pkgsrc_dirs: List[Path]) -> List[DistinfoEntry]:
        if len(self.distinfo_entries) > 0:
            return self.distinfo_entries

        distinfo_files = []
        for line in os.popen(f'{pkg_info} -q -b "{self.file}"').readlines():
            m = re.match(r'(?x) ([^\s:]+): \t \$NetBSD: .*?,v \s+ ([0-9.]+)', line)
            if m and f'./{m.group(1)}'.endswith('/distinfo'):
                distinfo_files.append(Path(m.group(1)))

        #print(f'package {self.pkgname} has distinfo files: {distinfo_files}')

        for distinfo_file in distinfo_files:
            for pkgsrc_dir in pkgsrc_dirs:
                distinfo = pkgsrc_dir / distinfo_file
                #print(f'distinfo {distinfo}')
                if distinfo.exists():
                    #print(f'exists')
                    for distinfo_entry in Distdir.load_distinfo(pkgsrc_dir, distinfo):
                        #print(f'entry {distinfo_entry}')
                        self.distinfo_entries.append(distinfo_entry)

        return self.distinfo_entries


class Distdir(NamedTuple):
    """
    A directory containing distribution files, such as /pub/pkgsrc/distfiles.

    Each such directory is connected to one or more directories containing
    binary packages, such as:
        /pub/pkgsrc/packages/NetBSD/amd64/2022Q4/All
        /pub/pkgsrc/packages/Linux/sparc/HEAD/All

    Each such directory is connected to one or more pkgsrc trees, such as:
        /usr/pkgsrc-trunk
        /usr/pkgsrc-2022Q4
    """

    distdir: Path
    database: Path
    packages_dirs: List[Path]
    pkgsrc_dirs: List[Path]

    def validate(self):
        distfiles = self.load_distfiles()
        distinfo_entries = {}  # XXX: self.load_pkgsrc()
        binary_packages = self.load_binary_packages()

        for distfile in distfiles:
            debug('distfile %s', distfile)
        for binary_package in binary_packages:
            debug('%s', binary_package)
        for distinfo_entry in sorted(distinfo_entries.values(), key=lambda e: e[0].distfile):
            debug('%s', distinfo_entry)

        self.validate_no_src_on_ftp(distfiles, binary_packages)

        print("TODO: validate that GPL files are still there even after removing the binary package")

    def validate_no_src_on_ftp(self, distfiles: List[Path], binary_packages: List[BinaryPackage]):
        for binary_package in binary_packages:
            for distinfo_entry in binary_package.load_distinfo_entries(self.pkgsrc_dirs):
                if binary_package.no_src_on_ftp() != '':
                    if (self.distdir / distinfo_entry.distfile).exists():
                        print(f"error: '{distinfo_entry.distfile}' must not be in '{self.distdir}' because the package '{binary_package.pkgname}' has NO_SRC_ON_FTP '{binary_package.no_src_on_ftp()}'.")

    def load_distfiles(self):
        distfiles: Set[Path] = set()
        for root, dirs, files in os.walk(self.distdir):
            for file in files:
                distfiles.add(Path(root, file).relative_to(self.distdir))
        return sorted(distfiles)

    def load_binary_packages(self) -> List[BinaryPackage]:
        binary_package_files: Set[Path] = set()
        for packages_dir in self.packages_dirs:
            for root, _, files in os.walk(packages_dir):
                for file in files:
                    if file.endswith('.tgz'):
                        binary_package_files.add(Path(root, file))

        binary_packages = []
        for binary_package_file in binary_package_files:
            binary_package = self.load_binary_package(binary_package_file)
            if binary_package:
                binary_packages.append(binary_package)

        return sorted(binary_packages, key=lambda p: p.pkgname)

    @staticmethod
    def load_binary_package(file: Path) -> Optional[BinaryPackage]:
        return BinaryPackage(file, file.name[:-len('.tgz')], {}, [])

    @staticmethod
    def list_distinfo_files(pkgsrc_dir: Path):
        for root, _, files in os.walk(pkgsrc_dir):
            for file in files:
                if file == 'distinfo':
                    yield Path(root, file).relative_to(pkgsrc_dir)

    def load_pkgsrc(self) -> Dict[Path, List[DistinfoEntry]]:
        info: Dict[Path, List[DistinfoEntry]] = {}

        for pkgsrc_dir in self.pkgsrc_dirs:
            for file in self.list_distinfo_files(pkgsrc_dir):
                for entry in self.load_distinfo(pkgsrc_dir, file):
                    if entry.distfile not in info:
                        info[entry.distfile] = list()
                    info[entry.distfile].append(entry)

        return info

    @staticmethod
    def load_distinfo(pkgsrc_dir: Path, distinfo: Path) -> List[DistinfoEntry]:
        by_path: Dict[Path, DistinfoEntry] = {}

        with open(Path(pkgsrc_dir, distinfo), 'r') as f:
            for line in f:
                m = re.match(r'(?x) (\S+) \s \( (\S+) \) \s = \s (\S+)', line)
                if m:
                    algorithm, path, value = m.groups()
                    path = Path(path)
                    if path not in by_path:
                        by_path[path] = DistinfoEntry(path, {}, pkgsrc_dir, distinfo)
                    by_path[path].hashes[algorithm] = value
        return list(by_path.values())


def load_configuration(file: str) -> List[Distdir]:
    distdirs: List[Distdir] = []

    with open(file) as f:
        distdir: Optional[Path] = None
        database: Optional[Path] = None
        packages_dirs = []
        pkgsrc_dirs = []

        lineno = 0
        for line in f:
            line = line.strip()
            lineno += 1

            if line == '' or line.startswith('#'):
                continue

            words = line.split()
            if len(words) != 2:
                raise ValueError(f'{file}:{lineno}: invalid line')
            cmd, arg = words

            if cmd == 'distdir':
                if distdir is not None:
                    distdirs.append(Distdir(distdir, database, packages_dirs, pkgsrc_dirs))
                    database = None
                    packages_dirs = []
                    pkgsrc_dirs = []
                distdir = Path(words[1])
                if not distdir.exists():
                    raise ValueError(f"{file}:{lineno}: '{distdir}' must be a directory")
                continue

            if distdir is None:
                raise ValueError(f"{file}:{lineno}: '{words[0]}' requires a preceding 'distdir'")

            if cmd == 'database':
                database = Path(arg)
            elif cmd == 'packages':
                packages = Path(arg)
                if not packages.exists():
                    raise ValueError(f"{file}:{lineno}: '{packages}' must be a directory")
                packages_dirs.append(packages)
            elif cmd == 'pkgsrc':
                pkgsrc = Path(arg)
                if not pkgsrc.exists():
                    raise ValueError(f"{file}:{lineno}: '{pkgsrc}' must be a directory")
                pkgsrc_dirs.append(pkgsrc)
            else:
                raise ValueError(f'{file}:{lineno}: {line}')

        if distdir is not None:
            distdirs.append(Distdir(distdir, database, packages_dirs, pkgsrc_dirs))

    return distdirs


def main() -> None:
    p = argparse.ArgumentParser(description='Validate distfiles directory')
    p.add_argument('file', nargs='+', help='configuration file')
    args = p.parse_args()

    distdirs: List[Distdir] = []
    for file in args.file:
        try:
            distdirs.extend(load_configuration(file))
        except ValueError as e:
            raise SystemExit(f'error: {e.args[0]}')

    for distdir in distdirs:
        distdir.validate()


if __name__ == '__main__':
    main()
