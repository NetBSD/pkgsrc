#! @PYTHONBIN@
# $NetBSD: url2pkg.py,v 1.8 2019/10/04 22:26:34 rillig Exp $

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
import glob
import os
import re
import subprocess
import sys
from typing import Callable, Dict, Iterator, List, Optional, Sequence, Union, Tuple


class Var:
    """ An abstract variable assignment for the package Makefile. """

    def __init__(self, name: str, op: str, value: str):
        self.name = name
        self.op = op
        self.value = value


class Varassign:
    """ A variable assignment including layout information. """

    def __init__(self, index: int, varname: str, op: str, indent: str,
                 value: str, space_after_value: str, comment: str):
        self.index = index
        self.varname = varname
        self.op = op
        self.indent = indent
        self.value = value
        self.space_after_value = space_after_value
        self.comment = comment


class Url2Pkg:

    def __init__(self):
        self.make = '@MAKE@'
        self.libdir = '@LIBDIR@'
        self.perl5 = '@PERL5@'
        self.pkgsrcdir = '@PKGSRCDIR@'
        self.pythonbin = '@PYTHONBIN@'
        self.pkgdir = '.'  # only overridable for tests
        self.verbose = False
        self.out = sys.stdout
        self.err = sys.stderr

    def debug(self, fmt: str, *args):
        if self.verbose:
            msg = fmt.format(*map(repr, args)) if len(args) else fmt
            self.err.write(f'url2pkg: {msg}\n')

    def find_package(self, pkgbase: str) -> str:
        candidates = glob.glob(f'{self.pkgsrcdir}/*/{pkgbase}')
        self.debug('candidates for package {0} are {1}', pkgbase, candidates)
        if len(candidates) != 1:
            return ''
        return candidates[0].replace(self.pkgsrcdir, '../..')

    def bmake(self, *args: str) -> None:
        self.debug('running bmake {0}', args)
        subprocess.check_call([self.make, *args], cwd=self.pkgdir)

    def show_var(self, varname: str) -> str:
        output = subprocess.check_output((self.make, 'show-var', 'VARNAME=' + varname))
        return output.decode('utf-8').strip()


class Lines:
    """
    A list of lines with high-level methods for manipulating variable
    assignments.
    """

    def __init__(self, *lines: str) -> None:
        self.lines = []
        for line in lines:
            self.add(line)

    @classmethod
    def read_from(cls, filename: str) -> 'Lines':
        pass

        lines = Lines()
        with open(filename) as f:
            for line in f:
                lines.add(line.rstrip('\n'))
        return lines

    def write_to(self, filename: str):
        with open(f'{filename}.tmp', 'w') as f:
            f.writelines(line + '\n' for line in self.lines)
        try:
            os.remove(filename)
        except OSError:
            pass
        os.rename(f'{filename}.tmp', filename)

    def add(self, *lines: Sequence[str]):
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
            name_op_len = (len(var.name) + len(var.op) + len('\t') + 7) // 8 * 8
            width = max(width, name_op_len)

        for var in relevant_vars:
            tabs = (width - len(var.name) - len(var.op) + 7) // 8
            self.add(var.name + var.op + '\t' * tabs + var.value)
        self.add('')

    def unique_varassign(self, varname: str) -> Optional[Varassign]:
        varassigns = self.all_varassigns(varname)
        return varassigns[0] if len(varassigns) == 1 else None

    def all_varassigns(self, varname: str) -> Sequence[Varassign]:
        varassigns = []
        for (i, line) in enumerate(self.lines):
            m = re.search(r'^(#?[\w+\-]+?)([!+:?]?=)([ \t]*)([^#\\]*?)(\s*)(#.*|)$', line)
            if m and m[1].lstrip('#') == varname:
                varassigns.append(Varassign(i, m[1], m[2], m[3], m[4], m[5], m[6]))
        return varassigns

    def set(self, varname: str, new_value: str) -> bool:
        """ Updates the value of an existing variable in the lines. """

        varassign = self.unique_varassign(varname)
        if varassign is not None:
            self.lines[varassign.index] = varname + varassign.op + varassign.indent + new_value
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

    def get(self, varname: str) -> str:
        """
        Returns the value from the only variable assignment, or an empty
        string.
        """
        varassign = self.unique_varassign(varname)
        return varassign.value if varassign is not None and varassign.varname == varname else ''

    def remove_if(self, varname: str, expected_value: str) -> bool:
        """ Removes a variable assignment if its value is the expected one. """
        for varassign in self.all_varassigns(varname):
            if varassign.value == expected_value:
                self.lines.pop(varassign.index)
                return True
        return False

    def index(self, pattern: str) -> int:
        """ Returns the first index where the pattern is found, or -1. """
        for (i, line) in enumerate(self.lines):
            if re.search(pattern, line):
                return i
        return -1


class Generator:
    """ Generates the initial package Makefile. """

    def __init__(self, url: str) -> None:
        self.url = url
        self.master_sites = ''
        self.distfile = ''
        self.homepage = ''
        self.extract_sufx = ''
        self.categories = ''
        self.github_project = ''
        self.github_release = ''
        self.dist_subdir = ''
        self.pkgname_prefix = ''
        self.pkgname_transform = ''
        self.maintainer = ''
        self.distname = ''
        self.pkgname = ''

    @staticmethod
    def foreach_site(action: Callable[[str, str], None]):
        varname = ''
        with open('../../mk/fetch/sites.mk') as sites_mk:
            for line in sites_mk:
                m = re.search(r'^(MASTER_SITE_.*)\+=', line)
                if m:
                    varname = m[1]
                    continue

                m = re.search(r'^\t(.*?)(?:\s+\\)?$', line)
                if not m:
                    continue

                site_url = m[1]
                action(varname, site_url)

    def adjust_site(self, varname: str, site_url: str):
        if not self.url.startswith(site_url):
            return

        rest = self.url[len(site_url):]
        m = re.search(r'^(.+)/([^/]+)$', rest)
        if not m:
            self.master_sites = f'${{{varname}}}'
            return

        subdir, self.distfile = m.groups()

        self.master_sites = f'${{{varname}:={subdir}/}}'
        if varname == 'MASTER_SITE_SOURCEFORGE':
            self.homepage = f'https://{subdir}.sourceforge.net/'
        elif varname == 'MASTER_SITE_GNU':
            self.homepage = f'https://www.gnu.org/software/{subdir}/'
        else:
            self.homepage = site_url[:-len(self.distfile)]

    def adjust_site_sourceforge(self):
        m = re.search(r'^https://downloads\.sourceforge\.net/project/([^/?]+)/[^?]+/([^/?]+)(?:[?].*)?$', self.url)
        if not m:
            return

        project, filename = m.groups()
        self.master_sites = f'${{MASTER_SITE_SOURCEFORGE:={project}/}}'
        self.homepage = f'https://{project}.sourceforge.net/'
        self.distfile = filename

    def adjust_site_GitHub_archive(self):
        m = re.search(r'^https://github\.com/(.+)/(.+)/archive/(.+)(\.tar\.gz|\.zip)$', self.url)
        if not m:
            return

        org, proj, tag, ext = m.groups()

        self.github_project = proj
        self.master_sites = f'${{MASTER_SITE_GITHUB:={org}/}}'
        self.homepage = f'https://github.com/{org}/{proj}/'
        if proj not in tag:
            self.pkgname_prefix = '${GITHUB_PROJECT}-'
            self.dist_subdir = '${GITHUB_PROJECT}'
        self.distfile = tag + ext

    def adjust_site_GitHub_release(self):
        m = re.search(r'^https://github\.com/(.+)/(.+)/releases/download/(.+)/(.+)(\.tar\.gz|\.zip)$', self.url)
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

        m = re.search(r'^(.*/)(.*)$', self.url)
        if not m:
            sys.exit(f'error: URL "{self.url}" must have at least one slash')

        self.master_sites = m[1]
        self.distfile = m[2]
        self.homepage = self.master_sites

    def determine_distname(self):
        m = re.search(r'^(.*?)((?:\.tar)?\.\w+)$', self.distfile)
        if m:
            distname, extract_sufx = m.groups()
        else:
            distname, extract_sufx = self.distfile, '# none'

        m = re.search(r'^v\d', distname)
        if m:
            self.pkgname_transform = ':S,^v,,'
        elif re.search(r'-v\d', distname) and not re.search(r'-v.*-v\d', distname):
            self.pkgname_transform = ':S,-v,-,'
        self.distname = distname

        main_category = re.search(r'.*/([^/]+)/[^/]+$', os.getcwd())[1]
        self.categories = main_category \
            if main_category not in ('local', 'wip') \
            else '# TODO: add primary category'

        if extract_sufx in ('.tar.gz', '.gem'):
            extract_sufx = ''
        self.extract_sufx = extract_sufx

        self.pkgname = '' if self.pkgname_prefix == '' and self.pkgname_transform == '' \
            else f'{self.pkgname_prefix}${{DISTNAME{self.pkgname_transform}}}'

        self.maintainer = \
            os.getenv('PKGMAINTAINER') or os.getenv('REPLYTO') \
            or 'INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org'

    def generate_lines(self) -> Lines:
        lines = Lines()
        lines.add('# $''NetBSD$')
        lines.add('')

        lines.add_vars(
            Var('GITHUB_PROJECT', '=', self.github_project),
            Var('DISTNAME', '=', self.distname),
            Var('PKGNAME', '=', self.pkgname),
            Var('CATEGORIES', '=', self.categories),
            Var('MASTER_SITES', '=', self.master_sites),
            Var('GITHUB_RELEASE', '=', self.github_release),
            Var('EXTRACT_SUFX', '=', self.extract_sufx),
            Var('DIST_SUBDIR', '=', self.dist_subdir),
        )

        lines.add_vars(
            Var('MAINTAINER', '=', self.maintainer),
            Var('HOMEPAGE', '=', self.homepage),
            Var('COMMENT', '=', 'TODO: Short description of the package'),
            Var('#LICENSE', '=', '# TODO: (see mk/license.mk)'),
        )

        lines.add('# url2pkg-marker (please do not remove this line.)')
        lines.add('.include "../../mk/bsd.pkg.mk"')

        return lines

    def generate_Makefile(self):
        self.foreach_site(self.adjust_site)
        self.adjust_site_sourceforge()
        self.adjust_site_GitHub_archive()
        self.adjust_site_GitHub_release()
        self.adjust_site_other()
        self.determine_distname()
        return self.generate_lines()

    def generate_package(self, up: Url2Pkg) -> Lines:
        pkgdir = up.pkgdir
        makefile = f'{pkgdir}/Makefile'
        descr = f'{pkgdir}/DESCR'
        plist = f'{pkgdir}/PLIST'

        initial_lines = self.generate_Makefile()

        try:
            os.rename(makefile, f'{makefile}.url2pkg~')
        except OSError:
            pass
        initial_lines.write_to(makefile)
        if not os.path.isfile(plist):
            Lines('@comment $''NetBSD$').write_to(plist)
        if not os.path.isfile(descr):
            Lines().write_to(descr)

        editor = os.getenv('PKGEDITOR') or os.getenv('EDITOR') or 'vi'
        subprocess.check_call([editor, makefile])

        up.bmake('distinfo')
        up.bmake('extract')

        return initial_lines


class Adjuster:
    """
    The following adjust_* functions are called after the distfiles have
    been downloaded and extracted. They inspect the extracted files
    and adjust the variable definitions in the package Makefile.
    """

    def __init__(self, up: Url2Pkg, url: str, initial_lines: Lines):

        self.up = up
        self.url = url
        self.initial_lines = initial_lines

        # the absolute pathname to the working directory, containing
        # the extracted distfiles.
        self.abs_wrkdir = ''

        # the absolute pathname to a subdirectory of abs_wrkdir, typically
        # containing package-provided Makefiles or configure scripts.
        self.abs_wrksrc = ''

        # the regular files and directories relative to abs_wrksrc.
        self.wrksrc_files: List[str] = []
        self.wrksrc_dirs: List[str] = []

        """
        The following variables may be set by the adjust_* subroutines and
        will later appear in the package Makefile:
        """

        # categories for the package, in addition to the usual
        # parent directory.
        self.categories: List[str] = []

        # the dependencies of the package, in the form
        # "package>=version:../../category/package".
        self.depends: List[str] = []
        self.build_depends: List[str] = []
        self.test_depends: List[str] = []

        # .include, interleaved with BUILDLINK3_API_DEPENDS.
        # These lines are added at the bottom of the Makefile.
        self.bl3_lines: List[str] = []

        # a list of pathnames relative to the package directory.
        # All these files will be included at the bottom of the Makefile.
        self.includes: List[str] = []

        # a list of variable assignments that will make up the fourth
        # paragraph of the package Makefile, where the build configuration
        # takes place.
        self.build_vars: List[Var] = []

        # similar to the @build_vars, but separated by an empty line in
        # the Makefile, thereby forming the fifth paragraph.
        self.extra_vars: List[Var] = []

        # variables from the initial Makefile whose values are replaced
        self.update_vars: Dict[str, str] = {}

        # these are inserted below the second paragraph in the Makefile.
        self.todos: List[str] = []

        # the package name is based on DISTNAME and modified by
        # pkgname_prefix and pkgname_transform.
        self.pkgname_prefix = ''  # example: ${PYPKGPREFIX}-
        self.pkgname_transform = ''  # example: :S,-v,-,

        # all lines of the package Makefile, for direct modification.
        self.makefile_lines = Lines()

        self.regenerate_distinfo = False

    def add_dependency(self, kind: str, pkgbase: str, constraint: str, dep_dir: str) -> None:
        """ add_dependency('DEPENDS', 'package', '>=1', '../../category/package') """

        self.up.debug('add_dependency: {0} {1} {2} {3}', kind, pkgbase, constraint, dep_dir)

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
                    self.bl3_lines.append(f'BUILDLINK_DEPENDS.{pkgid}+=\tbuild')
                self.bl3_lines.append(f'BUILDLINK_API_DEPENDS.{pkgid}+=\t{pkgid}{constraint}')
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

    def read_dependencies(self, cmd: str, env: Dict[str, str], cwd: str, pkgname_prefix: str) -> None:
        effective_env = dict(os.environ)
        effective_env.update(env)

        self.up.debug('reading dependencies: cd {0} && env {1} {2}', cwd, env, cmd)
        output = subprocess.check_output(args=cmd, shell=True, env=effective_env, cwd=cwd)

        dep_lines: List[Tuple[str, str, str, str]] = []
        for line in output.decode('utf-8').split('\n'):
            # example: DEPENDS   pkgbase>=1.2.3:../../category/pkgbase
            m = re.search(r'^(\w+)\t([^\s:>]+)(>[^\s:]+|)(?::(\.\./\.\./\S+))?$', line)
            if m:
                dep_lines.append((m[1], m[2], m[3] or '>=0', m[4] or ''))
                continue

            # example: var   VARNAME   value # possibly with comment
            m = re.search(r'^var\t(\S+)\t(.+)$', line)
            if m:
                self.update_vars[m[1]] = m[2]
                continue

            if line != '':
                self.up.debug('unknown dependency line: {0}', line)

        for dep_line in dep_lines:
            kind, pkgbase, constraint, dep_dir = dep_line

            if dep_dir == '' and pkgname_prefix != '':
                dep_dir = self.up.find_package(pkgname_prefix + pkgbase)
                if dep_dir != '':
                    pkgbase = pkgname_prefix + pkgbase
            if dep_dir == '':
                dep_dir = self.up.find_package(pkgbase)

            self.add_dependency(kind, pkgbase, constraint, dep_dir)

    def wrksrc_open(self, relative_pathname: str):
        return open(self.abs_wrksrc + '/' + relative_pathname)

    def wrksrc_find(self, what: Union[str, Callable[[str], bool]]) -> Iterator[str]:
        def search(f):
            print('search', f)
            return re.search(what, f) if type(what) == str else what(f)

        return list(sorted(filter(search, self.wrksrc_files)))

    def wrksrc_grep(self, filename: str, pattern: str) -> List[str]:
        with self.wrksrc_open(filename) as f:
            return [line for line in f if re.search(pattern, line)]

    def wrksrc_isdir(self, relative_pathname: str) -> bool:
        return os.path.isdir(self.abs_wrksrc + '/' + relative_pathname)

    def wrksrc_isfile(self, relative_pathname: str) -> bool:
        return os.path.isfile(self.abs_wrksrc + '/' + relative_pathname)

    def adjust_configure(self):
        if not self.wrksrc_isfile('configure'):
            return

        gnu = False
        some = False
        for configure in self.wrksrc_find(r'(^|/)configure$'):
            some = True
            if self.wrksrc_grep(configure, r'\b(Free Software Foundation|autoconf)\b'):
                gnu = True
        if some:
            varname = 'GNU_CONFIGURE' if gnu else 'HAS_CONFIGURE'
            self.build_vars.append(Var(varname, '=', 'yes'))

    def adjust_cmake(self):
        if self.wrksrc_isfile('CMakeLists.txt'):
            self.build_vars.append(Var('USE_CMAKE', '=', 'yes'))

    def adjust_meson(self):
        if self.wrksrc_isfile('meson.build'):
            self.includes.append('../../devel/py-meson/build.mk')

    def adjust_gconf2_schemas(self):
        gconf2_files = self.wrksrc_find(r'\.schemas(\.in)*$')
        if gconf2_files:
            self.includes.append('../../devel/GConf/schemas.mk')

        for f in gconf2_files:
            self.extra_vars.append(Var('GCONF_SCHEMAS', '+=', re.sub(r'(\.in)+$', '', f)))

    def adjust_libtool(self):
        if self.wrksrc_isfile('ltconfig') or self.wrksrc_isfile('ltmain.sh'):
            self.build_vars.append(Var('USE_LIBTOOL', '=', 'yes'))

        if self.wrksrc_isdir('libltdl'):
            self.includes.append('../../devel/libltdl/convenience.mk')

    def adjust_perl_module_Build_PL(self):
        # Example packages:
        # devel/p5-Algorithm-CheckDigits

        cmd = f'{self.up.perl5} -I{self.up.libdir} -I. Build.PL'
        self.read_dependencies(cmd, {}, self.abs_wrksrc, '')
        self.build_vars.append(Var('PERL5_MODULE_TYPE', '=', 'Module::Build'))

    def adjust_perl_module_Makefile_PL(self):
        # Example packages:
        # devel/p5-Algorithm-Diff (no dependencies)
        # devel/p5-Carp-Assert-More (dependencies without version numbers)
        # www/p5-HTML-Quoted (dependency with version number)

        # To avoid fix_up_makefile error for p5-HTML-Quoted, generate Makefile first.
        cmd1 = f'{self.up.perl5} -I. Makefile.PL </dev/null 1>&0 2>&0'
        subprocess.call(cmd1, shell=True, cwd=self.abs_wrksrc)

        cmd2 = f'{self.up.perl5} -I{self.up.libdir} -I. Makefile.PL'
        self.read_dependencies(cmd2, {}, self.abs_wrksrc, '')

    def adjust_perl_module_homepage(self):
        if '${MASTER_SITE_PERL_CPAN:' not in self.makefile_lines.get('MASTER_SITES'):
            return

        homepage = self.makefile_lines.get('HOMEPAGE')
        if homepage == '' or not self.url.startswith(homepage):
            return

        distname = self.makefile_lines.get('DISTNAME')
        module_name = re.sub(r'-v?[0-9].*', '', distname).replace('-', '::')
        self.makefile_lines.set('HOMEPAGE', f'https://metacpan.org/pod/{module_name}')

    def adjust_perl_module(self):
        if self.wrksrc_isfile('Build.PL'):
            self.adjust_perl_module_Build_PL()
        elif self.wrksrc_isfile('Makefile.PL'):
            self.adjust_perl_module_Makefile_PL()
        else:
            return

        distname = self.makefile_lines.get('DISTNAME')
        packlist = re.sub(r'-v?[0-9].*', '', distname).replace('-', '/')
        self.build_vars.append(Var('PERL5_PACKLIST', '=', f'auto/{packlist}/.packlist'))
        self.includes.append('../../lang/perl5/module.mk')
        self.pkgname_prefix = 'p5-'
        self.categories.append('perl5')
        self.adjust_perl_module_homepage()

        try:
            os.unlink('PLIST')
        except OSError:
            pass

    def adjust_python_module(self):
        # Example packages:
        # devel/py-ZopeComponent (dependencies, test dependencies)
        # devel/py-gflags (uses distutils.core instead of setuptools; BSD license)
        # devel/py-gcovr (uses setuptools; BSD license)

        if not self.wrksrc_isfile('setup.py'):
            return

        cmd = f'{self.up.pythonbin} setup.py build'
        env = {
            'PYTHONDONTWRITEBYTECODE': 'x',
            'PYTHONPATH': self.up.libdir
        }
        self.read_dependencies(cmd, env, self.abs_wrksrc, 'py-')

        self.pkgname_prefix = '${PYPKGPREFIX}-'
        self.categories.append('python')
        self.includes.append('../../lang/python/egg.mk')

    def adjust_cargo(self):
        if not self.wrksrc_isfile('Cargo.lock'):
            return

        with self.wrksrc_open('Cargo.lock') as f:
            for line in f:
                # "checksum cargo-package-name cargo-package-version
                m = re.search(r'^"checksum\s(\S+)\s(\S+)', line)
                if m:
                    self.build_vars.append(Var('CARGO_CRATE_DEPENDS', '+=', m[1] + '-' + m[2]))

        self.includes.append('../../lang/rust/cargo.mk')

    def adjust_pkg_config(self):
        def relevant(filename: str) -> bool:
            return filename.endswith('.pc.in') and not filename.endswith('-uninstalled.pc.in')

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

        def ignore(f: str) -> bool:
            return f.startswith('.') \
                   or f == 'pax_global_header' \
                   or f == 'package.xml' \
                   or f.endswith('.gemspec')

        files = list(filter(lambda x: not ignore(x), os.listdir(self.abs_wrkdir)))

        if len(files) == 1:
            if files[0] != self.makefile_lines.get('DISTNAME'):
                self.build_vars.append(Var('WRKSRC', '=', '${WRKDIR}/' + files[0]))
            self.abs_wrksrc = self.abs_wrkdir + '/' + files[0]
        elif len(files) == 0:
            self.build_vars.append(Var('WRKSRC', '=', '${WRKDIR}'))
            self.abs_wrksrc = self.abs_wrkdir
        else:
            wrksrc = '${WRKDIR} # More than one possibility -- please check manually.'
            self.build_vars.append(Var('WRKSRC', '=', wrksrc))
            self.abs_wrksrc = self.abs_wrkdir

    def adjust_lines_python_module(self, lines: Lines):

        initial_lines = self.initial_lines
        current_lines = self.makefile_lines

        if 'python' not in initial_lines.get('CATEGORIES'):
            return
        pkgbase = initial_lines.get('GITHUB_PROJECT')
        if pkgbase == '':
            return
        pkgbase1 = pkgbase[:1]
        pkgversion_norev = re.sub(r'^v', '', initial_lines.get('DISTNAME'))

        # don't risk to overwrite any changes made by the package developer.
        if '\n'.join(current_lines.lines) != '\n'.join(initial_lines.lines):
            lines.lines.insert(-2, '# TODO: Migrate MASTER_SITES to PYPI')
            return

        tx_lines = Lines(*self.makefile_lines.lines)
        if (tx_lines.remove('GITHUB_PROJECT')
                and tx_lines.set('DISTNAME', f'{pkgbase}-{pkgversion_norev}')
                and tx_lines.set('PKGNAME', '${PYPKGPREFIX}-${DISTNAME}')
                and tx_lines.set('MASTER_SITES', f'${{MASTER_SITE_PYPI:={pkgbase1}/{pkgbase}/}}')
                and tx_lines.remove('DIST_SUBDIR')):
            tx_lines.remove_if('EXTRACT_SUFX', '.zip')
            self.makefile_lines = tx_lines
            self.regenerate_distinfo = True

    def generate_adjusted_Makefile_lines(self) -> Lines:
        marker_index = self.makefile_lines.index(r'^# url2pkg-marker')
        if marker_index == -1:
            raise Exception('ERROR: didn\'t find the url2pkg marker in the Makefile.')

        lines = Lines(*self.makefile_lines.lines[: marker_index])

        if lines.get('PKGNAME') == '' and \
                (self.pkgname_prefix != '' or self.pkgname_transform != ''):
            distname_index = lines.index(r'^DISTNAME=(\t+)')
            if distname_index != -1:
                pkgname_line = f'PKGNAME=\t{self.pkgname_prefix}${{DISTNAME{self.pkgname_transform}}}'
                lines.lines.insert(distname_index + 1, pkgname_line)

        if self.todos:
            for todo in self.todos:
                lines.add('# TODO: ' + todo)
            lines.add('')

        depend_vars = []
        depend_vars.extend(Var('BUILD_DEPENDS', '+=', d) for d in self.build_depends)
        depend_vars.extend(Var('DEPENDS', '+=', d) for d in self.depends)
        depend_vars.extend(Var('TEST_DEPENDS', '+=', d) for d in self.test_depends)
        lines.add_vars(*depend_vars)

        lines.add_vars(*self.build_vars)
        lines.add_vars(*self.extra_vars)

        lines.add(*self.bl3_lines)
        lines.add(*(f'.include "{include}"' for include in self.includes))

        lines.add(*self.makefile_lines.lines[marker_index + 1:])

        lines.append('CATEGORIES', ' '.join(self.categories))

        self.adjust_lines_python_module(lines)

        for varname in self.update_vars:
            self.up.debug('update_var {0} {1}', varname, self.update_vars[varname])
            lines.set(varname, self.update_vars[varname])

        return lines

    def adjust_package_from_extracted_distfiles(self):

        def scan(basedir: str, pattern: str) -> List[str]:
            full_paths = glob.glob(f'{basedir}/{pattern}', recursive=True)
            return list(f[len(basedir) + 1:] for f in full_paths)

        self.up.debug('Adjusting the Makefile')
        self.makefile_lines = Lines.read_from(self.up.pkgdir + '/Makefile')

        self.abs_wrkdir = self.up.show_var('WRKDIR')
        self.determine_wrksrc()
        self.wrksrc_files = scan(self.abs_wrksrc, '**')
        self.wrksrc_dirs = scan(self.abs_wrksrc, '**/')

        self.adjust_configure()
        self.adjust_cmake()
        self.adjust_meson()
        self.adjust_gconf2_schemas()
        self.adjust_libtool()
        self.adjust_perl_module()
        self.adjust_python_module()
        self.adjust_cargo()
        self.adjust_pkg_config()
        self.adjust_po()
        self.adjust_use_languages()

        self.generate_adjusted_Makefile_lines().write_to(self.up.pkgdir + '/Makefile')

        if self.regenerate_distinfo:
            self.up.bmake('distinfo')


def main():
    if not os.path.isfile('../../mk/bsd.pkg.mk'):
        sys.exit(f'ERROR: {sys.argv[0]} must be run from a package directory (.../pkgsrc/category/package).')

    up = Url2Pkg()
    try:
        opts, args = getopt.getopt(sys.argv[1:], 'v', ['verbose'])
        for (opt, _) in opts:
            if opt in ('-v', '--verbose'):
                up.verbose = True
    except getopt.GetoptError:
        sys.exit(f'usage: {sys.argv[0]} [-v|--verbose] [URL]')

    url = args[0] if args else input('URL: ')

    if not glob.glob('w*/.extract_done') or not os.path.isfile('Makefile'):
        initial_lines = Generator(url).generate_package(up)
    else:
        initial_lines = Generator(url).generate_lines()

    Adjuster(up, url, initial_lines).adjust_package_from_extracted_distfiles()

    print('')
    print('Remember to run pkglint when you\'re done.')
    print('See ../../doc/pkgsrc.txt to get some help.')
    print('')


if __name__ == '__main__':
    main()
