#! @PYTHONBIN@
# $NetBSD: url2pkg.py,v 1.41 2022/02/06 21:07:44 rillig Exp $

# Copyright (c) 2019 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Roland Illig.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.


# Overview
#
# The url2pkg program gets a URL and produces a pkgsrc package from it,
# filling in several defaults in order to reduce the amount of manual work.
#
# This happens in two phases. Phase 1 is done by the Generator and generates
# an initial Makefile, just enough to download the distfile. Phase 2 then
# takes the generated Makefile and applies various adjustments for different
# types of packages, such as Perl or Python modules. This is done by the
# Adjuster class.


import getopt
import os
import re
import subprocess
import sys
from pathlib import Path
from typing import Any, Callable, Dict, List, NamedTuple, NoReturn, \
    Optional, Set, Tuple, Union


class Var(NamedTuple):
    """ An abstract variable assignment for the package Makefile. """
    name: str
    op: str
    value: str


class Varassign(NamedTuple):
    """ A variable assignment including layout information. """
    index: int
    varname: str
    op: str
    indent: str
    value: str
    space_after_value: str
    comment: str


class Globals:
    make: str
    libdir: str
    perl5: str
    pkgsrcdir: Union[Path, Any]
    pythonbin: str
    pkgdir: Union[Path, Any]
    out: Any
    err: Any
    verbose: bool

    def __init__(self):
        self.make = os.getenv('MAKE') or '@MAKE@'
        self.libdir = '@LIBDIR@'
        self.perl5 = '@PERL5@'
        self.pkgsrcdir = Path(os.getenv('PKGSRCDIR') or '@PKGSRCDIR@')
        self.pythonbin = '@PYTHONBIN@'

        # the following are overridden in tests
        self.pkgdir = Path('.')
        self.out = sys.stdout
        self.err = sys.stderr

        self.verbose = False

    def debug(self, fmt: str, *args):
        if self.verbose:
            msg = fmt.format(*map(repr, args)) if len(args) else fmt
            self.err.write(f'url2pkg: {msg}\n')

    def find_package(self, pkgbase: str) -> str:
        candidates = list(self.pkgsrcdir.glob(f'*/{pkgbase}'))
        self.debug('candidates for package {0} are {1}', pkgbase, candidates)
        if len(candidates) != 1:
            return ''
        return str(candidates[0]).replace(str(self.pkgsrcdir), '../..')

    def bmake(self, *args: str) -> None:
        self.debug('running bmake {0} in {1}', args, str(self.pkgdir))
        subprocess.check_call([self.make, *args], cwd=self.pkgdir)

    def show_var(self, varname: str) -> str:
        output = subprocess.check_output(
            (self.make, 'show-var', 'VARNAME=' + varname))
        return output.decode('utf-8').strip()

    def pkgsrc_license(self, license_name: str) -> str:
        comment = ''

        def suffix(suf: str, comm: str):
            nonlocal license_name, comment
            if comment == '' and license_name.endswith(suf):
                comment = f'\t# {comm}'
                license_name = license_name[:-len(suf)].rstrip()

        suffix('| file LICENSE', 'OR file LICENSE')
        suffix('+ file LICENSE', '+ file LICENSE')

        known_licenses = (
            ('2-clause-bsd', 'BSD-2', 'bsd2', 'BSD_2_clause'),
            # ('2-clause-bsd OR modified-bsd OR original-bsd', 'BSD'),
            # XXX: the above is questionable since it may be too specific
            ('acm-license', 'ACM'),
            ('apache-1.1 OR apache-2.0', 'APACHE'),
            ('apache-2.0', 'Apache 2', 'Apache 2.0', 'apache2',
             'Apache Software License', 'Apache License 2.0',
             'Apache License (== 2.0)'),
            ('apache-2.0 AND lppl-1.3c', 'apache2lppl', 'apache2lppl1.3c',
             'lppl1.3capache2'),
            ('artistic OR artistic-2.0', 'ARTISTIC'),
            ('artistic-2.0', 'artistic_2'),
            ('boost-license', 'BSL-1.0'),
            ('cc-by-v4.0', 'cc-by-4'),
            ('cc0-1.0-universal', 'CC0'),
            ('gfsl', 'gfl'),
            ('gnu-fdl-v1.3', 'fdl'),
            ('gnu-gpl-v1', 'GPL-1'),
            ('gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3', 'GPL'),
            ('gnu-gpl-v2', 'gpl', 'gpl2', 'GPL-2'),
            ('gnu-gpl-v2 AND cc-by-sa-v4.0', 'gpl3+cc-by-sa-4'),
            ('gnu-gpl-v2 AND lppl-1.3c', 'lpplgpl', 'gpl2lppl'),
            ('gnu-gpl-v2 AND ofl-v1.1 AND lppl-1.3c', 'gplofllppl'),
            ('gnu-gpl-v2 OR gnu-gpl-v3',
             'GPL-2 | GPL-3', 'GPL (>= 2)', 'GPL (>= 2.0)'),
            ('gnu-gpl-v3', 'gpl3', 'GPL-3',
             'GNU Lesser General Public License (LGPL), Version 3'),
            ('gnu-gpl-v3', 'GPL (>= 3)'),
            ('gnu-lgpl-v2', 'LGPL', 'LGPL-2'),
            ('gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3', 'LGPL'),
            ('gnu-lgpl-v2.1', 'LGPL-2.1'),
            ('gnu-lgpl-v3', 'LGPL-3'),
            ('gnu-lgpl-v2 OR gnu-lgpl-v3', 'LGPL-2 | LGPL-3'),
            ('gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3', 'LGPL (>= 2)'),
            ('lppl-1.0', 'lppl1'),
            ('lppl-1.2', 'lppl1.2'),
            ('lppl-1.3c', 'lppl', 'lppl1.3', 'lppl1.3c'),
            ('lucent', 'LUCENT', 'Lucent Public License'),
            ('mit', 'MIT', 'MIT License'),
            ('mit\t# + file LICENSE OR unlimited',
             'MIT + file LICENSE | Unlimited'),
            ('mit AND lppl-1.3c', 'mitlppl'),
            ('modified-bsd', 'bsd3', 'BSD 3 clause', 'BSD_3_clause'),
            ('ofl-v1.1', 'ofl'),
            ('ofl-v1.1 AND lppl-1.3c', 'ofllppl1.3', 'ofllppl1.3c', 'ofllppl'),
            ('${PERL5_LICENSE}', 'perl'),
            ('postgresql-license', 'POSTGRESQL'),
            ('public-domain', 'pd'),
            ('python-software-foundation', 'PSF', 'PSF license',
             'Python Software Foundation License'),
            ('zpl-2.1', 'ZPL 2.1'),
        )

        lower = license_name.lower()
        for group in known_licenses:
            if lower in map(str.lower, group):
                return group[0] + comment
        if (self.pkgsrcdir / 'licenses' / lower).is_file():
            return lower + comment
        return ''


class Lines:
    """
    A list of lines (typically from a Makefile, but other file types work as
    well) with high-level methods for manipulating variable assignments.
    """
    lines: List[str]

    def __init__(self, *lines: str) -> None:
        self.lines = []
        for line in lines:
            self.add(line)

    @classmethod
    def read_from(cls, src: Union[Path, Any]) -> 'Lines':
        return Lines(*src.read_text().splitlines())

    def write_to(self, dst: Union[Path, Any]):
        tmp = dst.with_name(f'{dst.name}.tmp')
        with tmp.open('w') as f:
            f.writelines(line + '\n' for line in self.lines)
        tmp.replace(dst)

    def all_varassigns(self, varname: str) -> List[Varassign]:
        varassigns = []
        for (i, line) in enumerate(self.lines):
            pattern = r'''(?x)
                ^
                ([#]?[\w+\-]+?)  # varname
                ([!+:?]?=)       # op
                ([ \t]*)         # indent
                ([^#\\]*?)       # value
                (\s*)            # space_after_value
                ([#].*|)         # comment
                $
                '''
            m = re.search(pattern, line)
            if m and m[1].lstrip('#') == varname.lstrip('#'):
                varassigns.append(Varassign(i, *m.groups()))
        return varassigns

    def unique_varassign(self, varname: str) -> Optional[Varassign]:
        varassigns = self.all_varassigns(varname)
        return varassigns[0] if len(varassigns) == 1 else None

    def get(self, varname: str) -> str:
        """
        Returns the value from the only variable assignment, or an empty
        string.
        """
        varassign = self.unique_varassign(varname)
        if varassign is not None and varassign.varname == varname:
            return varassign.value
        return ''

    def index(self, pattern: str) -> int:
        """ Returns the first index where the pattern is found, or -1. """
        for (i, line) in enumerate(self.lines):
            if re.search(pattern, line):
                return i
        return -1

    def add(self, *lines: str):
        for line in lines:
            assert type(line) == str, type(line)
            self.lines.append(line)

    def add_vars(self, *vars: Var):
        """
        Appends the given variable assignments to the lines, aligning the
        variable values vertically.
        """

        relevant_vars = [var for var in vars if var.value != '']
        if not relevant_vars:
            return

        width = 0
        for var in relevant_vars:
            indent_len = len(var.name) + len(var.op) + len('\t')
            name_op_len = (indent_len + 7) // 8 * 8
            width = max(width, name_op_len)

        for var in relevant_vars:
            tabs = (width - len(var.name) - len(var.op) + 7) // 8
            self.add(var.name + var.op + '\t' * tabs + var.value)
        self.add('')

    def set(self, varname: str, new_value: str) -> bool:
        """ Updates the value of an existing variable in the lines. """

        varassign = self.unique_varassign(varname)
        if varassign is not None:
            self.lines[varassign.index] = \
                varname + varassign.op + varassign.indent + new_value
        return varassign is not None

    def append(self, varname: str, value: str) -> bool:
        """ Appends to the value of an existing variable in the lines. """
        varassign = self.unique_varassign(varname)
        if varassign is None or value == '':
            return False

        before = ' ' if re.search(r'\S$', varassign.value) else ''
        after = '' if varassign.comment == '' else ' '
        self.lines[varassign.index] = \
            f'{varassign.varname}{varassign.op}{varassign.indent}' \
            f'{varassign.value}{before}{value}{after}{varassign.comment}'
        return True

    def remove(self, varname: str) -> bool:
        """ Removes the unique variable assignment. """
        varassign = self.unique_varassign(varname)
        if varassign is not None:
            self.lines.pop(varassign.index)
        return varassign is not None

    def remove_if(self, varname: str, expected_value: str) -> bool:
        """ Removes a variable assignment if its value is the expected one. """
        for varassign in self.all_varassigns(varname):
            if varassign.value == expected_value:
                self.lines.pop(varassign.index)
                return True
        return False


class PackageVars:
    """ Determines the package variables from a distfile URL. """
    url: str
    master_sites: str
    distfile: str
    homepage: str
    extract_sufx: str
    categories: str
    github_project: str
    github_tag: str
    github_release: str
    dist_subdir: str
    pkgname_prefix: str
    pkgname_transform: str
    maintainer: str
    distname: str
    pkgname: str

    def __init__(self, url: str, pkgsrcdir: Path) -> None:
        self.url = url
        self.master_sites = ''
        self.distfile = ''
        self.homepage = ''
        self.extract_sufx = ''
        self.categories = ''
        self.github_project = ''
        self.github_tag = ''
        self.github_release = ''
        self.dist_subdir = ''
        self.pkgname_prefix = ''
        self.pkgname_transform = ''
        self.maintainer = ''
        self.distname = ''
        self.pkgname = ''

        self.adjust_site_SourceForge()
        self.adjust_site_GitHub_archive()
        self.adjust_site_GitHub_release()
        self.adjust_site_CPAN()
        self.adjust_site_from_sites_mk(pkgsrcdir)
        self.adjust_site_PyPI()
        self.adjust_site_other()
        self.adjust_everything_else()

    def adjust_site_from_sites_mk(self, pkgsrcdir: Path):
        if self.master_sites != '':
            return

        varname = ''
        with open(pkgsrcdir / 'mk/fetch/sites.mk') as sites_mk:
            for line in sites_mk:
                m = re.search(r'^(MASTER_SITE_.*)\+=', line)
                if m:
                    varname = m[1]
                    continue

                m = re.search(r'^\t(.*?)(?:\s+\\)?$', line)
                if m:
                    self.adjust_site_from_site_var(varname, m[1])

    def adjust_site_from_site_var(self, varname: str, site_url: str):

        url_noproto = re.sub(r'^\w+://', '', self.url)
        site_url_noproto = re.sub(r'^\w+://', '', site_url)

        if not url_noproto.startswith(site_url_noproto):
            return

        rest = url_noproto[len(site_url_noproto):]
        if '/' not in rest:
            self.master_sites = f'${{{varname}}}'
            self.distfile = rest
            self.homepage = '# TODO'
            return

        subdir, self.distfile = re.search(r'^(.*/)(.*)$', rest).groups()

        self.master_sites = f'${{{varname}:={subdir}}}'
        if varname == 'MASTER_SITE_GNU':
            self.homepage = f'https://www.gnu.org/software/{subdir}'
        else:
            self.homepage = self.url[:-len(self.distfile)] + ' # TODO: check'

        if varname == 'MASTER_SITE_R_CRAN':
            sys.exit('url2pkg: to create R packages, '
                     'use pkgtools/R2pkg instead')

    def adjust_site_CPAN(self):
        pattern = r'''(?x)
            ^
            https://cpan.metacpan.org/authors
            /id/(?:\w+/)+
            (\w+-)+         # namespace prefixes
            (               # distname
                (\w+)       # project name
                -v?[0-9].+
            )
            $
            '''
        m = re.search(pattern, self.url)
        if not m:
            return

        prefixes, distfile, name = m.groups()
        prefixes_slash = prefixes.replace('-', '/')
        prefixes_colon = prefixes.replace('-', '::')
        self.master_sites = f'${{MASTER_SITE_PERL_CPAN:={prefixes_slash}}}'
        self.homepage = f'https://metacpan.org/pod/{prefixes_colon}{name}'
        self.distfile = f'{prefixes}{distfile}'
        self.pkgname_prefix = 'p5-'

    def adjust_site_SourceForge(self):
        pattern = r'''(?x)
            ^
            https?://downloads\.sourceforge\.net/(?:project|sourceforge)/
            ([^/?]+)/       # project name
            ((?:[^/?]+/)*)  # subdirectories
            ([^/?]+)        # filename
            (?:\?.*)?       # query parameters
            $
            '''
        m = re.search(pattern, self.url)
        if not m:
            return

        project, subdir, filename = m.groups()
        self.master_sites = f'${{MASTER_SITE_SOURCEFORGE:={project}/{subdir}}}'
        self.homepage = f'https://{project}.sourceforge.net/'
        self.distfile = filename

    def adjust_site_PyPI(self):
        pattern = r'''(?x)
            ^
            https://files\.pythonhosted\.org/packages/
            ../../.{60}/  # hash
            (             # distfile
            (.*)          #     project
            -[0-9].*      #     version
            \.tar\.gz
            )
            $
            '''
        m = re.search(pattern, self.url)
        if not m:
            return

        filename, project = m.groups()
        self.master_sites = f'${{MASTER_SITE_PYPI:={project[0]}/{project}/}}'
        self.homepage = f'https://pypi.org/project/{project}/'
        self.distfile = filename

    def adjust_site_GitHub_archive(self):
        pattern = r'''(?x)
            ^
            https://github\.com/
            (.+)/               # org
            (.+)/archive/       # proj
            ((?:.+/)?           # tag
                     (.+))      # distname
            (\.tar\.gz|\.zip)   # ext
            $
            '''
        m = re.search(pattern, self.url)
        if not m:
            return

        org, proj, tag, distname, ext = m.groups()

        self.master_sites = f'${{MASTER_SITE_GITHUB:={org}/}}'
        self.homepage = f'https://github.com/{org}/{proj}/'

        m = re.search(r'^refs/tags/v(\d[\d.]*)$', tag)
        if m:
            version = m.group(1)
            self.distfile = f'{proj}-{version}{ext}'
            self.github_tag = f'refs/tags/v${{PKGVERSION_NOREV}}'
            return

        self.github_project = proj
        self.github_tag = tag
        if proj not in tag:
            self.pkgname_prefix = '${GITHUB_PROJECT}-'
            self.dist_subdir = '${GITHUB_PROJECT}'
        self.distfile = distname + ext

    def adjust_site_GitHub_release(self):
        pattern = r'''(?x)
            ^https://github\.com/
            (.+)/               # org
            (.+)/               # proj
            releases/download/
            (.+)/               # tag
            (.+)                # base
            (\.tar\.gz|\.zip)$  # ext
            '''
        m = re.search(pattern, self.url)
        if not m:
            return

        org, proj, tag, base, ext = m.groups()

        self.github_project = proj
        self.master_sites = f'${{MASTER_SITE_GITHUB:={org}/}}'
        self.homepage = f'https://github.com/{org}/{proj}/'
        if proj not in base:
            self.github_project = proj
            self.dist_subdir = '${GITHUB_PROJECT}'
        self.github_release = '${DISTNAME}' if tag == base else tag
        self.distfile = base + ext

    def adjust_site_other(self):
        if self.master_sites != '':
            return

        base_url, self.distfile = re.search(r'^(.*/)(.*)$', self.url).groups()

        self.master_sites = base_url
        self.homepage = base_url

    def adjust_everything_else(self):
        m = re.search(r'^(.*?)((?:\.tar)?\.\w+)$', self.distfile)
        if m:
            distname, extract_sufx = m.groups()
        else:
            distname, extract_sufx = self.distfile, '# none'
        self.distname = distname

        if re.search(r'^v\d+\.', distname):
            self.pkgname_transform = ':S,^v,,'
        elif re.search(r'-v\d+\.', distname) \
                and not re.search(r'-v.*-v\d+\.', distname):
            self.pkgname_transform = ':S,-v,-,'

        main_category = Path.cwd().parts[-2]
        self.categories = main_category \
            if main_category not in ('local', 'wip') \
            else '# TODO: add primary category'

        if extract_sufx in ('.tar.gz', '.gem'):
            extract_sufx = ''
        self.extract_sufx = extract_sufx

        self.pkgname = '' \
            if self.pkgname_prefix == '' and self.pkgname_transform == '' \
            else f'{self.pkgname_prefix}${{DISTNAME{self.pkgname_transform}}}'

        self.maintainer = \
            os.getenv('PKGMAINTAINER') or os.getenv('REPLYTO') \
            or 'INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org'

    def package_dir(self) -> str:
        """Generate the suggested directory name for the package."""

        if self.github_project != '':
            return self.github_project

        m = re.fullmatch(r'(.*?)-v?[0-9].*', self.distname)
        if not m:
            return ''
        if 'MASTER_SITE_PYPI' in self.master_sites:
            return f'py-{m[1]}'
        if 'MASTER_SITE_PERL_CPAN' in self.master_sites:
            return f'p5-{m[1]}'
        return m[1]


class Generator:
    """ Generates the initial package Makefile. """
    vars: PackageVars

    def __init__(self, url: str):
        self.vars = PackageVars(url, Path('../..'))

    def generate_Makefile(self) -> Lines:
        vars = self.vars
        lines = Lines()
        lines.add('# $''NetBSD$')
        lines.add('')

        lines.add_vars(
            Var('GITHUB_PROJECT', '=', vars.github_project),
            Var('GITHUB_TAG', '=', vars.github_tag),
            Var('DISTNAME', '=', vars.distname),
            Var('PKGNAME', '=', vars.pkgname),
            Var('CATEGORIES', '=', vars.categories),
            Var('MASTER_SITES', '=', vars.master_sites),
            Var('GITHUB_RELEASE', '=', vars.github_release),
            Var('EXTRACT_SUFX', '=', vars.extract_sufx),
            Var('DIST_SUBDIR', '=', vars.dist_subdir),
        )

        lines.add_vars(
            Var('MAINTAINER', '=', vars.maintainer),
            Var('HOMEPAGE', '=', vars.homepage),
            Var('COMMENT', '=', 'TODO: Short description of the package'),
            Var('#LICENSE', '=', '# TODO: (see mk/license.mk)'),
        )

        lines.add('# url2pkg-marker (please do not remove this line.)')
        lines.add('.include "../../mk/bsd.pkg.mk"')

        return lines

    def generate_package(self, g: Globals) -> Lines:
        pkgdir = g.pkgdir
        makefile = pkgdir / 'Makefile'
        plist = pkgdir / 'PLIST'

        initial_lines = self.generate_Makefile()

        try:
            makefile.replace(f'{makefile}.url2pkg~')
        except OSError:
            pass
        initial_lines.write_to(makefile)

        plist_lines = [
            f'@comment $''NetBSD$',
            f'@comment TODO: to fill this file with the file listing:',
            f'@comment TODO: 1. run "{g.make} package"',
            f'@comment TODO: 2. run "{g.make} print-PLIST"'
        ]
        plist.is_file() or Lines(*plist_lines).write_to(plist)

        g.bmake('clean', 'distinfo', 'extract')

        return initial_lines


class Adjuster:
    """
    After the distfile has been downloaded and extracted, the
    adjust_* methods of this class inspect the extracted files
    and adjust the variable definitions in the package Makefile.
    """
    g: Globals
    url: str
    initial_lines: Lines

    # the absolute pathname to the working directory, containing
    # the extracted distfiles.
    abs_wrkdir: Union[Path, Any]

    # the absolute pathname to a subdirectory of abs_wrkdir, typically
    # containing package-provided Makefiles or configure scripts.
    abs_wrksrc: Union[Path, Any]

    # the regular files and directories relative to abs_wrksrc.
    wrksrc_files: List[str]
    wrksrc_dirs: List[str]

    """
    The following variables may be set by the adjust_* subroutines and
    will later appear in the package Makefile:
    """

    # categories for the package, in addition to the usual
    # parent directory.
    categories: List[str]

    # the dependencies of the package, in the form
    # "package>=version:../../category/package".
    depends: List[str]
    build_depends: List[str]
    test_depends: List[str]

    # .include, interleaved with BUILDLINK3_API_DEPENDS.
    # These lines are added at the bottom of the Makefile.
    bl3_lines: List[str]

    # a list of pathnames relative to the package directory.
    # All these files will be included at the bottom of the Makefile.
    includes: List[str]

    # the tools for USE_TOOLS. Examples are sed, echo, printf, perl5.
    tools: Set[str]

    # a list of variable assignments that will make up the fourth
    # paragraph of the package Makefile, where the build configuration
    # takes place.
    build_vars: List[Var]

    # similar to the @build_vars, but separated by an empty line in
    # the Makefile, thereby forming the fifth paragraph.
    extra_vars: List[Var]

    # these are inserted below the second paragraph in the Makefile.
    todos: List[str]

    # the package name is based on DISTNAME and modified by
    # pkgname_prefix and pkgname_transform.
    pkgname_prefix: str  # example: ${PYPKGPREFIX}-
    pkgname_transform: str  # example: :S,-v,-,

    # all lines of the package Makefile, for direct modification.
    makefile_lines: Lines

    regenerate_distinfo: bool

    descr_lines: List[str]

    def __init__(self, g: Globals, url: str, initial_lines: Lines):
        self.g = g
        self.url = url
        self.initial_lines = initial_lines
        self.abs_wrkdir = Path('')
        self.abs_wrksrc = Path('')
        self.wrksrc_files = []
        self.wrksrc_dirs = []
        self.categories = []
        self.depends = []
        self.build_depends = []
        self.test_depends = []
        self.bl3_lines = []
        self.includes = []
        self.build_vars = []
        self.tools = set()
        self.extra_vars = []
        self.todos = []
        self.pkgname_prefix = ''
        self.pkgname_transform = ''
        self.makefile_lines = Lines()
        self.regenerate_distinfo = False
        self.descr_lines = []

    def add_dependency(self, kind: str, pkgbase: str, constraint: str,
                       dep_dir: str) -> None:
        """
        add_dependency('DEPENDS', 'package', '>=1', '../../category/package')
        """

        self.g.debug('add_dependency: {0} {1} {2} {3}',
                     kind, pkgbase, constraint, dep_dir)

        def bl3_identifier():
            try:
                with open(dep_dir + '/buildlink3.mk') as f:
                    for line in f:
                        m = re.search(r'^BUILDLINK_TREE\+=\s*(\S+)$', line)
                        if m:
                            return m[1]
            except OSError:
                pass
            return ''

        if dep_dir != '':
            pkgid = bl3_identifier()
            if pkgid != '':
                if kind == 'BUILD_DEPENDS':
                    self.bl3_lines.append(
                        f'BUILDLINK_DEPENDS.{pkgid}+=\tbuild')
                self.bl3_lines.append(
                    f'BUILDLINK_API_DEPENDS.{pkgid}+=\t{pkgbase}{constraint}')
                self.bl3_lines.append(f'.include "{dep_dir}/buildlink3.mk"')
                return

        value = f'{pkgbase}{constraint}:{dep_dir}' \
            if dep_dir != '' and os.path.isfile(f'{dep_dir}/Makefile') \
            else f'# TODO: {pkgbase}{constraint}'

        if kind == 'DEPENDS':
            self.depends.append(value)
        elif kind == 'BUILD_DEPENDS':
            self.build_depends.append(value)
        elif kind == 'TEST_DEPENDS':
            self.test_depends.append(value)
        else:
            self.todos.append(f'dependency {kind} {value}')

    def read_dependencies(self, cmd: str, env: Dict[str, str],
                          cwd: Union[Path, Any], pkgdir_prefix: str,
                          pkgname_prefix: str) -> None:
        effective_env = dict(os.environ)
        effective_env.update(env)

        self.g.debug('reading dependencies: cd {0} && env {1} {2}',
                     str(cwd), env, cmd)
        output: bytes = subprocess.check_output(args=cmd, shell=True,
                                                env=effective_env, cwd=cwd)

        license_name = ''
        license_default = ''

        dep_lines: List[Tuple[str, str, str, str]] = []
        for line in output.decode('utf-8').splitlines():
            # example: DEPENDS   pkgbase>=1.2.3:../../category/pkgbase
            depends_re = r'^(\w+)\t([^\s:>]+)(>[^\s:]+|)(?::(\.\./\.\./\S+))?$'
            m = re.search(depends_re, line)
            if m:
                dep_lines.append((m[1], m[2], m[3] or '>=0', m[4] or ''))
                continue

            # example: var   VARNAME   value # possibly with comment
            m = re.search(r'^var\t(\S+)\t(.+)$', line)
            if m:
                self.set_or_add(m[1], m[2])
                continue

            m = re.search(r'^cmd\t(\S+)\t(.+)$', line)
            if m:
                cmd, arg = m.groups()
                if cmd == 'license':
                    license_name = arg
                elif cmd == 'license_default':
                    license_default = arg
                else:
                    self.g.debug('unknown command: {0}', line)
                continue

            if line != '':
                self.g.debug('unknown dependency line: {0}', line)

        self.set_license(license_name, license_default)
        self.add_dependencies(pkgdir_prefix, pkgname_prefix, dep_lines)

    def add_dependencies(self, pkgdir_prefix: str, pkgname_prefix: str,
                         dep_lines: List[Tuple[str, str, str, str]]):
        for dep_line in dep_lines:
            kind, pkgbase, constraint, dep_dir = dep_line

            if dep_dir == '' and pkgdir_prefix != '':
                dep_dir = self.g.find_package(pkgdir_prefix + pkgbase)
                if dep_dir != '':
                    pkgbase = pkgname_prefix + pkgbase
            if dep_dir == '':
                dep_dir = self.g.find_package(pkgbase)

            self.add_dependency(kind, pkgbase, constraint, dep_dir)

    def set_or_add(self, varname: str, value: str):
        if not self.makefile_lines.set(varname, value):
            self.extra_vars.append(Var(varname, '=', value))

    def set_license(self, license_name: str, license_default: str):
        pkgsrc_license_name = self.g.pkgsrc_license(license_name)
        if pkgsrc_license_name != '':
            self.set_or_add('LICENSE', pkgsrc_license_name)
        elif license_default != '':
            self.set_or_add('#LICENSE', license_default)

    def wrksrc_open(self, relative_pathname: str):
        return (self.abs_wrksrc / relative_pathname).open()

    def wrksrc_head(self, relative_pathname: str, n: int):
        full_name = self.abs_wrksrc / relative_pathname
        try:
            with full_name.open(encoding="UTF-8") as f:
                return f.read().splitlines()[:n]
        except IOError:
            return []

    def wrksrc_find(self,
                    what: Union[str, Callable[[str], bool]]) -> List[str]:
        def search(f):
            return re.search(what, f) if type(what) == str else what(f)

        return list(sorted(filter(search, self.wrksrc_files)))

    def wrksrc_grep(self, filename: str,
                    pattern: str) -> List[Union[str, List[str]]]:
        with self.wrksrc_open(filename) as f:
            matches = []
            for line in f:
                line = line.rstrip('\n')
                m = re.search(pattern, line)
                if m:
                    groups = list(m.groups())
                    matches.append(groups if groups else line)
            return matches

    def wrksrc_isdir(self, relative_pathname: str) -> bool:
        return (self.abs_wrksrc / relative_pathname).is_dir()

    def wrksrc_isfile(self, relative_pathname: str) -> bool:
        return (self.abs_wrksrc / relative_pathname).is_file()

    def adjust_descr(self):
        for filename in ('README', 'README.txt', 'README.md'):
            lines = self.wrksrc_head(filename, 21)
            if len(lines) == 21:
                lines[-1] = '...'
            if lines:
                self.descr_lines = [
                    f'TODO: Adjust the following lines from {filename}',
                    '',
                    *lines]
                return

        self.descr_lines = [
            'TODO: Fill in a short description of the package.',
            'TODO: It should be between 3 and 20 lines.']

    def adjust_configure(self):
        if not self.wrksrc_isfile('configure'):
            return

        configures = self.wrksrc_find(r'(^|/)configure$')
        if not configures:
            return

        gnu = any(self.wrksrc_grep(configure,
                                   r'\b(Free Software Foundation|autoconf)\b')
                  for configure in configures)
        varname = 'GNU_CONFIGURE' if gnu else 'HAS_CONFIGURE'
        self.build_vars.append(Var(varname, '=', 'yes'))

    def adjust_cmake(self):
        if self.wrksrc_isfile('CMakeLists.txt'):
            self.build_vars.append(Var('USE_CMAKE', '=', 'yes'))

    def adjust_gnu_make(self):
        if self.wrksrc_isfile('Makefile') \
                and self.wrksrc_grep('Makefile', r'^(?:ifeq|ifdef)\b'):
            self.tools.add('gmake')

    def adjust_meson(self):
        if self.wrksrc_isfile('meson.build'):
            self.includes.append('../../devel/meson/build.mk')

    def adjust_gconf2_schemas(self):
        gconf2_files = self.wrksrc_find(r'\.schemas(\.in)*$')
        if gconf2_files:
            self.includes.append('../../devel/GConf/schemas.mk')

        for f in gconf2_files:
            self.extra_vars.append(
                Var('GCONF_SCHEMAS', '+=', re.sub(r'(\.in)+$', '', f)))

    def adjust_libtool(self):
        if self.wrksrc_isfile('ltconfig') or self.wrksrc_isfile('ltmain.sh'):
            self.build_vars.append(Var('USE_LIBTOOL', '=', 'yes'))

        if self.wrksrc_isdir('libltdl'):
            self.includes.append('../../devel/libltdl/convenience.mk')

    def adjust_perl_module_Build_PL(self):
        # Example packages:
        # devel/p5-Algorithm-CheckDigits

        cmd = f'{self.g.perl5} -I{self.g.libdir} -I. Build.PL'
        self.read_dependencies(cmd, {}, self.abs_wrksrc, '', '')
        self.build_vars.append(Var('PERL5_MODULE_TYPE', '=', 'Module::Build'))

    def adjust_perl_module_Makefile_PL(self):
        # Example packages:
        # devel/p5-Algorithm-Diff (no dependencies, no license)
        # devel/p5-Carp-Assert-More (dependencies without version numbers)
        # www/p5-HTML-Quoted (dependency with version number)

        # To avoid fix_up_makefile error for p5-HTML-Quoted, generate Makefile
        # first.
        cmd1 = f'{self.g.perl5} -I. Makefile.PL </dev/null 1>&0 2>&0'
        subprocess.call(cmd1, shell=True, cwd=self.abs_wrksrc)

        cmd2 = f'{self.g.perl5} -I{self.g.libdir} -I. Makefile.PL'
        self.read_dependencies(cmd2, {}, self.abs_wrksrc, '', '')

    def adjust_perl_module_homepage(self):
        if '${MASTER_SITE_PERL_CPAN:' \
                not in self.makefile_lines.get('MASTER_SITES'):
            return

        homepage = self.makefile_lines.get('HOMEPAGE')
        if homepage == '' or not self.url.startswith(homepage):
            return

        distname = self.makefile_lines.get('DISTNAME')
        module_name = re.sub(r'-v?[0-9].*', '', distname).replace('-', '::')
        self.makefile_lines.set('HOMEPAGE',
                                f'https://metacpan.org/pod/{module_name}')

    def adjust_perl_module(self):
        if self.wrksrc_isfile('Build.PL'):
            self.adjust_perl_module_Build_PL()
        elif self.wrksrc_isfile('Makefile.PL'):
            self.adjust_perl_module_Makefile_PL()
        else:
            return

        distname = self.makefile_lines.get('DISTNAME')
        packlist = re.sub(r'-v?[0-9].*', '', distname).replace('-', '/')
        self.build_vars.append(
            Var('PERL5_PACKLIST', '=', f'auto/{packlist}/.packlist'))
        self.includes.append('../../lang/perl5/module.mk')
        self.pkgname_prefix = 'p5-'
        self.categories.append('perl5')
        self.adjust_perl_module_homepage()

        try:
            (self.g.pkgdir / 'PLIST').unlink()
        except OSError:
            pass

    def adjust_python_module(self):
        # Example packages:
        # devel/py-ZopeComponent (dependencies, test dependencies)
        # devel/py-gflags (uses distutils.core instead of setuptools;
        #     BSD license)
        # devel/py-gcovr (uses setuptools; BSD license)

        if not self.wrksrc_isfile('setup.py'):
            return

        cmd = f'{self.g.pythonbin} setup.py build'
        env = {
            'PYTHONDONTWRITEBYTECODE': 'x',
            'PYTHONPATH': self.g.libdir
        }
        self.read_dependencies(cmd, env, self.abs_wrksrc, 'py-', '${PYPKGPREFIX}-')

        self.pkgname_prefix = '${PYPKGPREFIX}-'
        self.categories.append('python')
        self.includes.append('../../lang/python/egg.mk')

    def adjust_cargo(self):
        if not self.wrksrc_isfile('Cargo.lock'):
            return

        # pull name and version from package entries
        with self.wrksrc_open('Cargo.lock') as f:
            name = ''
            version = ''
            for line in f:
                if line.startswith('[[package]]'):
                    # new package, reset name and version to be safe
                    name = ''
                    version = ''
                    continue

                m = re.match(r'^name\s=\s"(\S+)"', line)
                if m:
                    name = m[1]

                m = re.match(r'^version\s=\s"(\S+)"', line)
                if m:
                    version = m[1]

                if re.match(r'^source\s=\s"(\S+)"', line):
                    if name != '' and version != '':
                        self.build_vars.append(Var(
                            'CARGO_CRATE_DEPENDS', '+=', f'{name}-{version}'
                        ))
                    name = ''
                    version = ''

        self.includes.append('../../lang/rust/cargo.mk')

    def adjust_pkg_config(self):
        def relevant(filename: str) -> bool:
            return filename.endswith('.pc.in') \
                and not filename.endswith('-uninstalled.pc.in')

        pkg_config_files = self.wrksrc_find(relevant)

        if pkg_config_files:
            self.build_vars.append(Var('USE_TOOLS', '+=', 'pkg-config'))
        for f in pkg_config_files:
            self.extra_vars.append(Var('PKGCONFIG_OVERRIDE', '+=', f))

    def adjust_po(self):
        if self.wrksrc_find(r'\.(g?mo|po)$'):
            self.build_vars.append(Var('USE_PKGLOCALEDIR', '=', 'yes'))

    def adjust_use_languages(self):
        languages = []

        if self.wrksrc_find(r'\.(c|xs)$'):
            languages.append('c')
        if self.wrksrc_find(r'\.(cpp|c\+\+|cxx|cc|C)$'):
            languages.append('c++')
        if self.wrksrc_find(r'\.f$'):
            languages.append('fortran')

        use_languages = ' '.join(languages)
        if use_languages == '':
            use_languages = '# none'
        if use_languages != 'c':
            self.build_vars.append(Var('USE_LANGUAGES', '=', use_languages))

    def determine_wrksrc(self):
        """
        Sets abs_wrksrc depending on abs_wrkdir and the files found there.
        """

        def relevant(f: Union[Path, Any]) -> bool:
            return f.is_dir() and not f.name.startswith('.')

        subdirs = [f.name for f in self.abs_wrkdir.glob('*') if relevant(f)]

        if len(subdirs) == 1:
            if subdirs[0] != self.makefile_lines.get('DISTNAME'):
                self.build_vars.append(
                    Var('WRKSRC', '=', '${WRKDIR}/' + subdirs[0]))
            self.abs_wrksrc = self.abs_wrkdir / subdirs[0]
        elif len(subdirs) == 0:
            self.build_vars.append(Var('WRKSRC', '=', '${WRKDIR}'))
            self.abs_wrksrc = self.abs_wrkdir
        else:
            choices = ' '.join(subdirs)
            wrksrc = f'${{WRKDIR}} # TODO: one of {choices}, or leave it as-is'
            self.build_vars.append(Var('WRKSRC', '=', wrksrc))
            self.abs_wrksrc = self.abs_wrkdir

    def adjust_lines_python_module(self, lines: Lines):

        initial_lines = self.initial_lines  # generated by url2pkg
        edited_lines = self.makefile_lines  # edited by the package developer

        if 'python' not in lines.get('CATEGORIES'):
            return
        if lines.get('GITHUB_PROJECT') == '':
            return

        # don't risk overwriting any changes made by the package developer.
        if edited_lines.lines != initial_lines.lines:
            lines.lines.insert(-2, '# TODO: Migrate MASTER_SITES '
                                   'to MASTER_SITE_PYPI')
            return

        pkgbase = initial_lines.get('GITHUB_PROJECT')
        pkgbase1 = pkgbase[:1] if pkgbase != '' else ''
        pkgversion_norev = re.sub(r'^v', '', initial_lines.get('DISTNAME'))

        tx_lines = Lines(*self.makefile_lines.lines)
        if not (tx_lines.remove('GITHUB_PROJECT')
                and tx_lines.set('DISTNAME', f'{pkgbase}-{pkgversion_norev}')
                and tx_lines.set('PKGNAME', '${PYPKGPREFIX}-${DISTNAME}')
                and tx_lines.set('MASTER_SITES',
                                 f'${{MASTER_SITE_PYPI:='
                                 f'{pkgbase1}/{pkgbase}/}}')
                and tx_lines.remove('DIST_SUBDIR')):
            return

        tx_lines.remove_if('GITHUB_TAG', initial_lines.get('DISTNAME'))
        tx_lines.remove_if('EXTRACT_SUFX', '.zip')

        g = self.g
        try_mk = g.pkgdir / 'try-pypi.mk'
        tx_lines.write_to(try_mk)
        args = [g.make, '-f', str(try_mk), 'distinfo']
        g.debug('running {0} to try PyPI', args)
        fetch_ok = subprocess.call(args, cwd=g.pkgdir) == 0
        try_mk.unlink()
        if not fetch_ok:
            return

        lines.lines = tx_lines.lines
        self.regenerate_distinfo = True

    def generate_lines(self) -> Lines:
        marker_index = self.makefile_lines.index(r'^# url2pkg-marker')
        if marker_index == -1:
            sys.exit('error: didn\'t find the url2pkg marker in the Makefile.')

        lines = Lines(*self.makefile_lines.lines[: marker_index])

        if lines.get('PKGNAME') == '' and \
           (self.pkgname_prefix != '' or self.pkgname_transform != ''):
            distname_index = lines.index(r'^DISTNAME=(\t+)')
            if distname_index != -1:
                pkgname_line = f'PKGNAME=\t{self.pkgname_prefix}' \
                               f'${{DISTNAME{self.pkgname_transform}}}'
                lines.lines.insert(distname_index + 1, pkgname_line)

        if self.todos:
            for todo in self.todos:
                lines.add('# TODO: ' + todo)
            lines.add('')

        depend_vars = []
        depend_vars.extend(
            Var('BUILD_DEPENDS', '+=', d) for d in self.build_depends)
        depend_vars.extend(
            Var('DEPENDS', '+=', d) for d in self.depends)
        depend_vars.extend(
            Var('TEST_DEPENDS', '+=', d) for d in self.test_depends)
        lines.add_vars(*depend_vars)

        build_vars = self.build_vars
        if self.tools:
            build_vars.append(
                Var('USE_TOOLS', '+=', ' '.join(sorted(self.tools))))
        lines.add_vars(*build_vars)
        lines.add_vars(*self.extra_vars)

        lines.add(*self.bl3_lines)
        lines.add(*(f'.include "{include}"' for include in self.includes))

        lines.add(*self.makefile_lines.lines[marker_index + 1:])

        lines.append('CATEGORIES', ' '.join(self.categories))

        self.adjust_lines_python_module(lines)

        return lines

    def adjust(self):

        def scan(basedir: Union[Path, Any],
                 only: Callable[[Path], bool]) -> List[str]:
            relevant = (f for f in basedir.rglob('*') if only(f))
            relative = (str(f.relative_to(basedir)) for f in relevant)
            return list(sorted((f for f in relative if not f.startswith('.'))))

        self.g.debug('Adjusting the Makefile')
        self.makefile_lines = Lines.read_from(self.g.pkgdir / 'Makefile')

        self.abs_wrkdir = Path(self.g.show_var('WRKDIR'))
        self.determine_wrksrc()
        self.wrksrc_dirs = scan(self.abs_wrksrc, Path.is_dir)
        self.wrksrc_files = scan(self.abs_wrksrc, Path.is_file)

        self.adjust_descr()
        self.adjust_configure()
        self.adjust_cmake()
        self.adjust_gnu_make()
        self.adjust_meson()
        self.adjust_gconf2_schemas()
        self.adjust_libtool()
        self.adjust_perl_module()
        self.adjust_python_module()
        self.adjust_cargo()
        self.adjust_pkg_config()
        self.adjust_po()
        self.adjust_use_languages()

        self.generate_lines().write_to(self.g.pkgdir / 'Makefile')
        descr = (self.g.pkgdir / 'DESCR')
        descr.is_file() or Lines(*self.descr_lines).write_to(descr)

        if self.regenerate_distinfo:
            self.g.bmake('distinfo')


def usage() -> NoReturn:
    sys.exit(f'usage: {sys.argv[0]} [-v|--verbose] URL')


def main(argv: List[str], g: Globals):
    try:
        opts, args = getopt.getopt(argv[1:], 'v', ['verbose'])
        for (opt, _) in opts:
            if opt in ('-v', '--verbose'):
                g.verbose = True
    except getopt.GetoptError:
        usage()

    url = args[0] if len(args) == 1 else usage()
    if not re.fullmatch(r'\w+://[!-~]+?/[!-~]+', url):
        sys.exit(f'url2pkg: invalid URL: {url}')

    if os.path.isfile('../mk/bsd.pkg.mk'):
        vars = PackageVars(url, Path('..'))
        dir = vars.package_dir()

        if dir == '':
            sys.exit(f'url2pkg: cannot determine package directory '
                     f'from distname \'{vars.distname}\'')
        if Path(dir).exists():
            sys.exit(f'url2pkg: package directory \'{dir}\' already exists')
        os.mkdir(dir)
        os.chdir(dir)

    if not os.path.isfile('../../mk/bsd.pkg.mk'):
        sys.exit(f'{argv[0]}: must be run from a package or category directory '
                 f'(.../pkgsrc/category[/package])')

    initial_lines = Generator(url).generate_package(g)
    Adjuster(g, url, initial_lines).adjust()

    g.out.write('\n')
    g.out.write('Remember to run pkglint when you\'re done.\n')
    g.out.write('See ../../doc/pkgsrc.txt to get some help.\n')
    g.out.write('\n')


if __name__ == '__main__':
    try:
        main(sys.argv, Globals())
    except KeyboardInterrupt:
        sys.exit(1)
