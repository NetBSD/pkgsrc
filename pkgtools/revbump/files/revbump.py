#!/usr/bin/env python3
#
# $NetBSD: revbump.py,v 1.3 2023/06/10 14:35:29 wiz Exp $
#
# Copyright (c) 2023 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Thomas Klausner.
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
#

import argparse
import glob
import os
import pathlib
import re
import subprocess
import sys

# only accept includes with ../../ or in the current directory
bl3_include_re = re.compile(r'\s*\.\s*include\s+"(\.\./\.\./[^/]*/[^/]*/|)([^/]*)"')
abi_depends_re = re.compile(r'^(BUILDLINK_ABI_DEPENDS.+=[ \t]+)')
bldir_re = re.compile(r'^BUILDLINK_PKGSRCDIR(.*=[ \t]+)')
pkgrevision_re = re.compile(r'PKGREVISION=([ \t]+)([0-9]+)$')
pr_before_re = re.compile(r'(?:CATEGORIES=|\.\s*include)([ \t]+)')
pr_after_re = re.compile(r'(?:PKGNAME=|COMMENT=)([ \t]+)')
python_fix_re = re.compile(r'py[0-9]*-')
ruby_fix_re = re.compile(r'ruby[0-9]*-')


def bl3bump(path):
    '''Update the ABI depends line in path/buildlink3.mk.'''
    old_path = args.pkgsrcdir + '/' + path + '/buildlink3.mk'
    if not pathlib.Path(old_path).exists():
        print(f'{old_path} does not exist, skipped')
        return
    new_path = old_path + '.modified'

    version_process = subprocess.run(['make', 'show-var', 'VARNAME=PKGNAME'],
                                     capture_output=True,
                                     check=True,
                                     cwd=args.pkgsrcdir + '/' + path,
                                     text=True)
    version = version_process.stdout
    last_dash = version.rfind('-')
    version = version[:last_dash] + '>=' + version[last_dash+1:]
    if python_fix_re.match(version):
        version = re.sub(python_fix_re, '${PYPKGPREFIX}-', version)
    if ruby_fix_re.match(version):
        version = re.sub(ruby_fix_re, '${RUBY_PKGPREFIX}-', version)

    output = []
    with open(old_path, 'r', encoding='utf-8') as input_file:
        done = False
        for line in input_file.readlines():
            if done:
                output.append(line)
            elif m := abi_depends_re.match(line):
                new_line = m.group(1) + version
                if line == new_line:
                    # no effective change to file, avoid changing it
                    return
                output.append(new_line)
                done = True
            elif m := bldir_re.match(line):
                output.append('BUILDLINK_ABI_DEPENDS' + m.group(1) + version)
                output.append(line)
                done = True
            else:
                output.append(line)

    if not done:
        print(f'{old_path}: failed to update BUILDLINK_ABI_DEPENDS to {version}, please handle manually')
        return

    with open(new_path, 'w', encoding='utf-8') as output_file:
        for line in output:
            output_file.write(line)
    os.rename(new_path, old_path)


def revbump(path):
    '''Update PKGREVISION in path/Makefile.'''
    old_path = args.pkgsrcdir + '/' + path + '/Makefile'
    if not pathlib.Path(old_path).exists():
        print(f'{old_path} does not exist, skipped')
        return

    new_path = old_path + '.modified'
    output = []
    with open(old_path, 'r', encoding='utf-8') as input_file:
        done = False
        for line in input_file.readlines():
            if done:
                output.append(line)
            elif m := pkgrevision_re.match(line):
                done = True
                output.append('PKGREVISION=' + m.group(1)
                              + str(int(m.group(2))+1) + '\n')
            else:
                output.append(line)
    if not done:
        output2 = []
        # some heuristics where to add a PKGREVISION line
        # mostly needed for packages that have a Makefile.common
        for line in output:
            if done:
                output2.append(line)
            elif m := pr_before_re.match(line):
                output2.append('PKGREVISION=' + m.group(1) + '1\n')
                output2.append(line)
                done = True
            elif m := pr_after_re.match(line):
                output2.append(line)
                output2.append('PKGREVISION=' + m.group(1) + '1\n')
                done = True
            else:
                output2.append(line)
        output = output2

    if not done:
        print(f'{old_path}: failed to update PKGREVISION, please handle manually')
        return

    with open(new_path, 'w', encoding='utf-8') as output_file:
        for line in output:
            output_file.write(line)
    os.rename(new_path, old_path)


def extract_includes(path):
    '''Read the interesting parts of a Makefile (fragment).'''
    file_content = []
    relative = relative_path(path)
    with open(path, 'r', encoding='utf-8') as f:
        for entry in f.readlines():
            if m := bl3_include_re.match(entry):
                file_path = m.group(1)
                file_name = m.group(2)
                if file_path.find('/mk/') != -1:
                    continue
                if len(file_path) == 0:
                    file_path = '../../' + relative[:relative.rfind('/')+1]
                file_content.append(file_path[6:] + file_name)
    return file_content


def relative_path(full_path):
    '''Strip pkgsrcdir from path.'''
    return full_path[len(args.pkgsrcdir)+1:]


parser = argparse.ArgumentParser(description='find all packages that' +
                                 ' link against a given package')
parser.add_argument('package', help='package for which we want to find' +
                    ' its dependencies')
parser.add_argument('-o', dest='output', default='commitlist',
                    help='output file containing the directories with changes',
                    action='store')
parser.add_argument('-p', dest='pkgsrcdir', default='/usr/pkgsrc',
                    help='path to the pkgsrc root directory', action='store')
parser.add_argument('-w', dest='wip', default=False,
                    help='include wip in search', action='store_true')
args = parser.parse_args()

if not pathlib.Path(args.pkgsrcdir).exists() or \
   not pathlib.Path(args.pkgsrcdir + '/doc').exists() or \
   not pathlib.Path(args.pkgsrcdir + '/mk').exists():
    print(f'invalid pkgsrc directory "{args.pkgsrcdir}"')
    sys.exit(1)

if args.package == 'lang/go':
    searchlist = ['lang/go/version.mk']
else:
    initial_bl3 = args.package.rstrip('/') + '/buildlink3.mk'
    if not pathlib.Path(args.pkgsrcdir + '/' + initial_bl3).exists():
        print(f'package {args.package} provides no buildlink3.mk file')
        sys.exit(1)
    searchlist = [initial_bl3]

bl3files = glob.glob(args.pkgsrcdir + '/*/*/buildlink3.mk')
bl3files.append(args.pkgsrcdir + '/lang/ocaml/ocaml.mk')
if not args.wip:
    bl3files = filter(lambda name: name.find('/wip/') == -1, bl3files)
# recursively find all buildlink3.mk files that directly or indirectly
# include the target package's buildlink3.mk file
bl3content = {}
for file in bl3files:
    includes = extract_includes(file)
    if len(includes) > 0:
        bl3content[file] = includes

bl3result = []
while len(searchlist) > 0:
    newlist = []
    for pattern in searchlist:
        bl3result.append(pattern)
        for key, value in dict(bl3content).items():
            if pattern in value:
                # remove entry so it is not found again
                # via a different include path
                del bl3content[key]
                # skip 'pkgsrcdir/'
                newlist.append(relative_path(key))
    searchlist = newlist
# not needed any longer
bl3content.clear()

makefiles = glob.glob(args.pkgsrcdir + '/*/*/Makefile*')
makefiles.extend(glob.glob(args.pkgsrcdir + '/*/*/*.mk'))
makefiles = list(filter(lambda name: name.find('/mk/') == -1
                        and not name.endswith('buildlink3.mk')
                        and not name.endswith('cargo-depends.mk')
                        and not name.endswith('go-modules.mk'),
                        makefiles))
if not args.wip:
    makefiles = list(filter(lambda name: name.find('/wip/') == -1, makefiles))

makefile_content = {}
for makefile in makefiles:
    includes = extract_includes(makefile)
    if len(includes) > 0:
        makefile_content[makefile] = includes
makefile_result = []
for makefile in makefiles:
    for pattern in bl3result:
        if makefile in makefile_content \
           and pattern in makefile_content[makefile]:
            makefile_result.append(relative_path(makefile))
            break

# for non-plain Makefile, look if they are included from somewhere else
possibly_included_files = list(filter(lambda name:
                                      not name.endswith('/Makefile'),
                                      makefile_result))
while len(possibly_included_files) > 0:
    newlist = []
    for pattern in possibly_included_files:
        for name, content in makefile_content.items():
            if pattern in content:
                makefile_result.append(relative_path(name))
                if not name.endswith('/Makefile'):
                    newlist.append(relative_path)
    possibly_included_files = newlist
# not needed any longer
makefile_content.clear()

# to be on the safe side, bump all p5-* Packages when perl is bumped
if args.package == 'lang/perl5':
    for file in glob.glob(args.pkgsrcdir + '/*/p5-*/Makefile'):
        makefile_result.append(relative_path(file))


directories = [path[:path.rfind('/')] for path in makefile_result + bl3result]
directories = filter(lambda name: name != args.package, directories)
with open(args.output, 'w', encoding='utf-8') as f:
    f.write(args.package + '\n')
    for directory in sorted(set(directories)):
        revbump(directory)
        f.write(directory + '\n')
for bl3file in sorted(set(bl3result)):
    bl3bump(bl3file[:-len('/buildlink3.mk')])
