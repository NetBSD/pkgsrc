#! @PYTHONBIN@
# $NetBSD: url2pkg.py,v 1.2 2019/10/03 12:52:54 rillig Exp $

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

import getopt
import glob
import os
import re
import subprocess
import sys
from os.path import isfile
from typing import Callable, Dict, Iterator, List, Optional, Sequence, Union


def cvsid(fmt: str) -> str:
    return fmt % ('$' + 'NetBSD$')


class Config:

    def __init__(self):
        self.make = '@MAKE@'
        self.libdir = '@LIBDIR@'
        self.perl5 = '@PERL5@'
        self.pkgsrcdir = '@PKGSRCDIR@'
        self.pythonbin = '@PYTHONBIN@'
        self.pkgdir = '.'  # only overridable for tests
        self.verbose = False


config = Config()
distname = ''


def debug(fmt: str, *args):
    if config.verbose:
        msg = fmt.format(*map(repr, args)) if len(args) else fmt
        sys.stderr.write('url2pkg: %s\n' % msg)


def run_editor(fname: str, lineno: int):
    editor = os.getenv('PKGEDITOR') or os.getenv('EDITOR') or 'vi'

    args: List[str] = [editor]
    if re.search(editor, r'(^|/)(mcedit|nano|pico|vi|vim)$'):
        args.append(f'+{lineno}')
    args.append(fname)

    code = subprocess.check_call(args)


def generate_initial_package_Makefile_lines(url):
    global distname

    master_site = ''
    master_sites = ''
    distfile = ''
    homepage = ''
    extract_sufx = ''
    categories = ''
    github_project = ''
    github_release = ''
    dist_subdir = ''
    pkgname_prefix = ''
    pkgname_transform = ''

    with open('../../mk/fetch/sites.mk') as sites_mk:
        for line in sites_mk:
            m = re.search(r'^(MASTER_SITE_.*)\+=', line)
            if m:
                master_site = m[1]
                continue

            m = re.search(r'^\t(.*?)(?:\s+\\)?$', line)
            if not m:
                continue

            site = m[1]
            if not url.startswith(site):
                continue

            rest = url[len(site):]
            m = re.search(r'^(.+)/([^/]+)$', rest)
            if not m:
                master_sites = "${%s}" % master_site
                continue

            subdir, distfile = m.groups()

            master_sites = '${%s:=%s/}' % (master_site, subdir)
            if master_site == 'MASTER_SITE_SOURCEFORGE':
                homepage = f'https://{subdir}.sourceforge.net/'
            elif master_site == 'MASTER_SITE_GNU':
                homepage = f'https://www.gnu.org/software/{subdir}/'
            else:
                homepage = url[:-len(distfile)]

    m = re.search(r'^https://downloads\.sourceforge\.net/project/([^/?]+)/[^?]+/([^/?]+)(?:[?].*)?$', url)
    if m:
        project, filename = m.groups()

        master_sites = '${MASTER_SITE_SOURCEFORGE:=%s/}' % project
        homepage = 'https://%s.sourceforge.net/' % project
        distfile = filename

    m = re.search(r'^https://github\.com/(.+)/(.+)/archive/(.+)(\.tar\.gz|\.zip)$', url)
    if m:
        org, proj, tag, ext = m.groups()

        github_project = proj
        master_sites = '${MASTER_SITE_GITHUB:=%s/}' % org
        homepage = 'https://github.com/%s/%s/' % (org, proj)
        if github_project not in tag:
            pkgname_prefix = '${GITHUB_PROJECT}-'
            dist_subdir = '${GITHUB_PROJECT}'
        distfile = tag + ext

    m = re.search(r'^https://github\.com/(.+)/(.+)/releases/download/(.+)/(.+)(\.tar\.gz|\.zip)$', url)
    if m:
        org, proj, tag, base, ext = m.groups()

        github_project = proj
        master_sites = '${MASTER_SITE_GITHUB:=%s/}' % org
        homepage = 'https://github.com/%s/%s/' % (org, proj)
        if proj not in base:
            github_project = proj
            dist_subdir = '${GITHUB_PROJECT}'
        github_release = '${DISTNAME}' if tag == base else tag
        distfile = base + ext

    if master_sites == '':
        m = re.search(r'^(.*/)(.*)$', url)
        master_sites = m[1]
        distfile = m[2]
        homepage = master_sites

    m = re.search(r'^(.*?)((?:\.tar)?\.\w+)$', distfile)
    if m:
        distname, extract_sufx = m.groups()
    else:
        distname, extract_sufx = distfile, '# none'

    m = re.search(r'^v\d', distname)
    if m:
        pkgname_transform = ':S,^v,,'
    elif re.search(r'-v\d', distname) and not re.search(r'-v.*-v\d', distname):
        pkgname_transform = ':S,-v,-,'

    main_category = re.search(r'.*/([^/]+)/[^/]+$', os.getcwd())[1]

    categories = main_category if main_category != 'wip' else '# TODO: add primary category'

    if extract_sufx == '.tar.gz' or extract_sufx == '.gem':
        extract_sufx = ''

    pkgname = '%s${DISTNAME%s}' % (pkgname_prefix, pkgname_transform)
    if pkgname == '${DISTNAME}':
        pkgname = ''

    maintainer = \
        os.getenv('PKGMAINTAINER') or os.getenv('REPLYTO') \
        or 'INSERT_YOUR_MAIL_ADDRESS_HERE'

    lines = Lines()
    lines.add(cvsid('# %s'))
    lines.add('')

    lines.add_vars(
        Var('GITHUB_PROJECT', '=', github_project),
        Var('DISTNAME', '=', distname),
        Var('PKGNAME', '=', pkgname),
        Var('CATEGORIES', '=', categories),
        Var('MASTER_SITES', '=', master_sites),
        Var('GITHUB_RELEASE', '=', github_release),
        Var('EXTRACT_SUFX', '=', extract_sufx),
        Var('DIST_SUBDIR', '=', dist_subdir),
    )

    lines.add_vars(
        Var('MAINTAINER', '=', maintainer),
        Var('HOMEPAGE', '=', homepage),
        Var('COMMENT', '=', 'TODO: Short description of the package'),
        Var('#LICENSE', '=', '# TODO: (see mk/license.mk)'),
    )

    lines.add('# url2pkg-marker (please do not remove this line.)')
    lines.add('.include "../../mk/bsd.pkg.mk"')

    return lines


def generate_initial_package(url):
    try:
        os.rename('Makefile', 'Makefile-url2pkg.bak')
    except OSError:
        pass
    generate_initial_package_Makefile_lines(url).write_to(config.pkgdir + '/Makefile')
    Lines(cvsid('@comment %s')).write_to(config.pkgdir + '/PLIST')
    Lines().write_to(config.pkgdir + '/DESCR')
    run_editor(config.pkgdir + '/Makefile', 5)

    bmake('distinfo')
    bmake('extract')


class Var:
    """ A variable assignment for the package Makefile """

    def __init__(self, name: str, op: str, value: str):
        self.name = name
        self.op = op
        self.value = value


def aligned(vars: List[Var]) -> List[str]:
    relevant = list(filter(lambda v: v.value != '', vars))
    if not relevant:
        return []

    def tabwidth(var: Var) -> int:
        return (len(var.name) + len(var.op) + len('\t') + 7) // 8 * 8

    width = max(map(tabwidth, relevant), default=0)

    aligned_lines = []
    for var in relevant:
        tabs = '\t' * ((width - len(var.name) - len(var.op) + 7) // 8)
        aligned_lines.append(var.name + var.op + tabs + var.value)

    aligned_lines.append('')
    return aligned_lines


class Varassign:

    def __init__(self, index: int, varname: str, op: str, indent: str,
                 value: str, space_after_value: str, comment: str):
        self.index = index
        self.varname = varname
        self.op = op
        self.indent = indent
        self.value = value
        self.space_after_value = space_after_value
        self.comment = comment


def find_package(pkgbase: str) -> str:
    candidates = glob.glob(config.pkgsrcdir + '/*/' + pkgbase)
    debug('candidates for package {0} are {1}', pkgbase, candidates)
    if len(candidates) != 1:
        return ''
    return candidates[0].replace(config.pkgsrcdir, '../..')


def bmake(*args: str) -> None:
    debug('running bmake {0}', args)
    subprocess.check_call([config.make] + list(args), cwd=config.pkgdir)


def show_var(varname: str) -> str:
    output = subprocess.check_output((config.make, 'show-var', 'VARNAME=' + varname))
    return output.decode('utf-8').strip()


class Lines:

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
        width = 0
        for var in vars:
            if var.value != '':
                name_op_len = (len(var.name) + len(var.op) + len('\t') + 7) // 8 * 8
                width = max(width, name_op_len)

        if width == 0:
            return

        for var in vars:
            if var.value != '':
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
        """ Changes the value of an existing variable in the lines. """

        varassign = self.unique_varassign(varname)
        if varassign is not None:
            self.lines[varassign.index] = varname + varassign.op + varassign.indent + new_value
        return varassign is not None

    def append(self, varname: str, value: str) -> None:
        """ Appends to the value of an existing variable in the lines. """
        if value == '':
            return
        varassign = self.unique_varassign(varname)
        # TODO: add a test for multiple assignments
        if varassign is not None:
            before = ' ' if re.search(r'\S$', varassign.value) else ''
            after = '' if varassign.comment == '' else ' '
            self.lines[varassign.index] = \
                varassign.varname + varassign.op + varassign.indent \
                + varassign.value + before + value + after \
                + varassign.comment
        return varassign is not None

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
        return varassign.value if varassign is not None else ''

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


class Adjuster:
    """
    The following adjust_* functions are called after the distfiles have
    been downloaded and extracted. They inspect the extracted files
    and adjust the variable definitions in the package Makefile.
    """

    def __init__(self):
        # the package name, including the version number.
        self.distname = distname

        # the absolute pathname to the working directory, containing
        # the extracted distfiles.
        self.abs_wrkdir = ''

        # the absolute pathname to a subdirectory of abs_wrkdir, typically
        # containing package-provided Makefiles or configure scripts.
        self.abs_wrksrc = ''

        # the regular files and directories relative to abs_wrksrc.
        self.wrksrc_files = []
        self.wrksrc_dirs = []

        """
        The following variables may be set by the adjust_* subroutines and
        will later appear in the package Makefile:
        """

        # categories for the package, in addition to the usual
        # parent directory.
        self.categories: List[str] = []

        # the dependencies of the package, in the form
        # "package>=version:../../category/package".
        self.depends = []
        self.build_depends = []
        self.test_depends = []

        # .include, interleaved with BUILDLINK3_API_DEPENDS.
        # These lines are added at the bottom of the Makefile.
        self.bl3_lines = []

        # a list of pathnames relative to the package path.
        # All these files will be included at the bottom of the Makefile.
        self.includes = []

        # a list of variable assignments that will make up the fourth
        # paragraph of the package Makefile, where the build configuration
        # takes place.
        self.build_vars = []

        # similar to the @build_vars, but separated by an empty line in
        # the Makefile, thereby forming the fifth paragraph.
        self.extra_vars = []

        # variables from the initial Makefile whose values are replaced
        self.update_vars: Dict[str, str] = {}

        # these are inserted below the second paragraph in the Makefile.
        self.todos = []

        # the package name is based on DISTNAME and modified by
        # pkgname_prefix and pkgname_transform.
        self.pkgname_prefix = ''  # example: ${PYPKGPREFIX}-
        self.pkgname_transform = ''  # example: :S,-v,-,

        # all lines of the package Makefile, for direct modification.
        self.makefile_lines = Lines()

        self.regenerate_distinfo = False

    def add_dependency(self, kind: str, pkgbase: str, constraint: str, dep_dir: str) -> None:
        """ add_dependency('DEPENDS', 'package', '>=1', '../../category/package') """
        if dep_dir != '' and isfile(dep_dir + '/buildlink3.mk'):
            # TODO: add kind to bl3_lines (BUILDLINK_DEPENDS)
            # TODO: add constraint to bl3_lines (BUILDLINK_API_DEPENDS)
            self.bl3_lines.append('.include "%s/buildlink3.mk"' % dep_dir)
            return

        value = pkgbase + constraint + ':' + dep_dir \
            if dep_dir != '' and isfile(dep_dir + '/Makefile') \
            else '# TODO: {0}{1}'.format(pkgbase, constraint)

        if kind == 'DEPENDS':
            self.depends.append(value)
        elif kind == 'BUILD_DEPENDS':
            self.build_depends.append(value)
        elif kind == 'TEST_DEPENDS':
            self.test_depends.append(value)
        else:
            self.todos.append('dependency {0} {1}'.format(kind, value))

    def read_dependencies(self, cmd: str, env: Dict[str, str], cwd: str, pkgname_prefix: str) -> None:
        dep_lines = []

        effective_env = dict(os.environ)
        effective_env.update(env)

        debug('reading dependencies: cd {0} && env {1} {2}', cwd, env, cmd)
        output = subprocess.check_output(
            args=cmd,
            shell=True,
            env=effective_env,
            cwd=cwd
        )

        for line in output.decode('utf-8').split('\n'):
            m = re.search(r'^(\w+)\t([^\s:>]+)(>[^\s:]+|)(?::(\.\./\.\./\S+))?$', line)
            if m:
                dep_lines.append([m[1], m[2], m[3] or '>=0', m[4] or ''])
                continue
            m = re.search(r'^var\t(\S+)\t(.+)$', line)
            if m:
                self.update_vars[m[1]] = m[2]
                continue
            if line != '':
                debug('unknown dependency line: {0}', line)

        for dep_line in dep_lines:
            type, pkgbase, constraint, dir = dep_line

            if dir == '' and pkgname_prefix != '':
                dir = find_package(pkgname_prefix + pkgbase)
                if dir != '':
                    pkgbase = pkgname_prefix + pkgbase
            if dir == '':
                dir = find_package(pkgbase)

            debug('add_dependency: {0} {1} {2} {3}', type, pkgbase, constraint, dir)
            self.add_dependency(type, pkgbase, constraint, dir)

    def wrksrc_find(self, what: Union[str, Callable]) -> Iterator[str]:
        def search(f):
            if type(what) == str:
                return re.search(what, f)
            return what(f)

        return list(filter(search, self.wrksrc_files))

    def wrksrc_isdir(self, relative_pathname: str) -> bool:
        return isfile(self.abs_wrksrc + '/' + relative_pathname)

    def wrksrc_isfile(self, relative_pathname: str) -> bool:
        return isfile(self.abs_wrksrc + '/' + relative_pathname)

    def wrksrc_open(self, relative_pathname: str):
        return open(self.abs_wrksrc + '/' + relative_pathname)

    def adjust_configure(self):
        if not self.wrksrc_isfile('configure'):
            return

        with self.wrksrc_open('configure') as f:
            for line in f:
                if 'autoconf' in line or 'Free Software Foundation' in line:
                    self.build_vars.append(Var('GNU_CONFIGURE', '=', 'yes'))
                    return

        self.build_vars.append(Var('HAS_CONFIGURE', '=', 'yes'))

    def adjust_cmake(self):
        if self.wrksrc_isfile('CMakeLists.txt'):
            self.build_vars.append(Var('USE_CMAKE', '=', 'yes'))

    def adjust_meson(self):
        if self.wrksrc_isfile('meson.build'):
            self.includes.append('../../devel/py-meson/build.mk')

    def adjust_gconf2_schemas(self):
        gconf2_files = self.wrksrc_find(r'schemas(?:\.in.*)$')
        if not gconf2_files:
            return
        for f in gconf2_files:
            m = re.search(r'(.*schemas)', f)
            if m:
                self.extra_vars.append(Var('GCONF_SCHEMAS', '+=', m[1]))
            self.includes.append('../../devel/GConf/schemas.mk')

    def adjust_libtool(self):
        if self.wrksrc_isfile('ltconfig') or self.wrksrc_isfile('ltmain.sh'):
            self.build_vars.append(Var('USE_LIBTOOL', '=', 'yes'))
        if self.wrksrc_isdir('libltdl'):
            self.includes.append('../../devel/libltdl/convenience.mk')

    def adjust_perl_module_Build_PL(self):
        """
        Example packages:
        devel/p5-Algorithm-CheckDigits
        """
        cmd = '%s -I%s -I. Build.PL' % (config.perl5, config.libdir)
        self.read_dependencies(cmd, {}, self.abs_wrksrc, '')
        self.build_vars.append(Var('PERL5_MODULE_TYPE', '=', 'Module::Build'))

    def adjust_perl_module_Makefile_PL(self):
        """
        Example packages:
        devel/p5-Algorithm-Diff (no dependencies)
        devel/p5-Carp-Assert-More (dependencies without version numbers)
        www/p5-HTML-Quoted (dependency with version number)
        """
        # To avoid fix_up_makefile error for p5-HTML-Quoted, generate Makefile first.
        cmd1 = '%s -I. Makefile.PL < /dev/null 1>&0 2>&0' % config.perl5
        cmd2 = '%s -I%s -I. Makefile.PL' % (config.perl5, config.libdir)
        subprocess.call(cmd1, shell=True, cwd=self.abs_wrksrc)
        self.read_dependencies(cmd2, {}, self.abs_wrksrc, '')

    def adjust_perl_module_homepage(self, url: str) -> None:
        if '${MASTER_SITE_PERL_CPAN:' in self.makefile_lines.get('MASTER_SITES'):
            homepage = self.makefile_lines.get('HOMEPAGE')
            if homepage != '' and url.startswith(homepage):
                module_name = re.sub(r'-v?[0-9].*', '', self.distname).replace('-', '::')
                self.makefile_lines.set('HOMEPAGE', f'https://metacpan.org/pod/{module_name}')

    def adjust_perl_module(self, url: str):
        if self.wrksrc_isfile('Build.PL'):
            self.adjust_perl_module_Build_PL()
        elif self.wrksrc_isfile('Makefile.PL'):
            self.adjust_perl_module_Makefile_PL()
        else:
            return

        packlist = re.sub(r'-v?[0-9].*', '', self.distname).replace('-', '/')
        self.build_vars.append(Var('PERL5_PACKLIST', '=', f'auto/{packlist}/.packlist'))
        self.includes.append('../../lang/perl5/module.mk')
        self.pkgname_prefix = 'p5-'
        self.categories.append('perl5')
        self.adjust_perl_module_homepage(url)

        os.unlink('PLIST')

    def adjust_python_module(self):
        """
        Example packages:
        devel/py-ZopeComponent (dependencies, test dependencies)
        devel/py-gflags (uses distutils.core instead of setuptools; BSD license)
        devel/py-gcovr (uses setuptools; BSD license)
        """

        if not self.wrksrc_isfile('setup.py'):
            return

        cmd = '%s setup.py build' % config.pythonbin
        env = {
            'PYTHONDONTWRITEBYTECODE': 'x',
            'PYTHONPATH': config.libdir
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
        def relevant(f: str) -> bool:
            return f.endswith('.pc.in') and not f.endswith('-uninstalled.pc.in')

        pkg_config_files = self.wrksrc_find(relevant)

        if pkg_config_files:
            self.build_vars.append(Var('USE_TOOLS', '+=', 'pkg-config'))
        for f in pkg_config_files:
            self.extra_vars.append(Var('PKGCONFIG_OVERRIDE', '+=', f))

    def adjust_po(self):
        if self.wrksrc_find(r'\.g?mo$'):
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
            if files[0] != self.distname:
                self.build_vars.append(Var('WRKSRC', '=', '${WRKDIR}/' + files[0]))
            self.abs_wrksrc = self.abs_wrkdir + '/' + files[0]
        elif len(files) == 0:
            self.build_vars.append(Var('WRKSRC', '=', '${WRKDIR}'))
            self.abs_wrksrc = self.abs_wrkdir
        else:
            wrksrc = '${WRKDIR} # More than one possibility -- please check manually.'
            self.build_vars.append(Var('WRKSRC', '=', wrksrc))
            self.abs_wrksrc = self.abs_wrkdir

    def adjust_lines_python_module(self, lines: Lines, url: str):

        initial_lines = generate_initial_package_Makefile_lines(url)
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
                and tx_lines.set('DISTNAME', '%s-%s' % (pkgbase, pkgversion_norev))
                and tx_lines.set('PKGNAME', '${PYPKGPREFIX}-${DISTNAME}')
                and tx_lines.set('MASTER_SITES', '${MASTER_SITE_PYPI:=%s/%s/}' % (pkgbase1, pkgbase))
                and tx_lines.remove('DIST_SUBDIR')
                and (tx_lines.remove_if('EXTRACT_SUFX', '.zip') or True)):
            self.makefile_lines = tx_lines
            self.regenerate_distinfo = True

    def generate_adjusted_Makefile_lines(self, url) -> Lines:
        marker_index = self.makefile_lines.index(r'^# url2pkg-marker')
        if marker_index == -1:
            raise Exception('ERROR: didn\'t find the url2pkg marker in the Makefile.')

        lines = Lines(*self.makefile_lines.lines[: marker_index])

        if lines.index(r'^PKGNAME=') == -1:
            distname_index = lines.index(r'^DISTNAME=(\t+)')
            if distname_index != -1:
                pkgname_line = 'PKGNAME=\t%s${DISTNAME%s}' % (self.pkgname_prefix, self.pkgname_transform)
                lines.lines.insert(distname_index + 1, pkgname_line)

        if self.todos:
            for todo in self.todos:
                lines.add('# TODO: ' + todo)
            lines.add('')

        depend_vars = []
        depend_vars.extend(map(lambda d: Var('BUILD_DEPENDS', '+=', d), self.build_depends))
        depend_vars.extend(map(lambda d: Var('DEPENDS', '+=', d), self.depends))
        depend_vars.extend(map(lambda d: Var('TEST_DEPENDS', '+=', d), self.test_depends))
        lines.add_vars(*depend_vars)

        lines.add_vars(*self.build_vars)
        lines.add_vars(*self.extra_vars)

        lines.add(*self.bl3_lines)
        lines.add(*map(lambda include: '.include "%s"' % include, self.includes))

        lines.add(*self.makefile_lines.lines[marker_index + 1:])

        lines.append('CATEGORIES', ' '.join(self.categories))

        self.adjust_lines_python_module(lines, url)

        for varname in self.update_vars:
            debug('update_var {0} {1}', varname, self.update_vars[varname])
            lines.set(varname, self.update_vars[varname])

        return lines

    def adjust_package_from_extracted_distfiles(self, url: str):

        debug('Adjusting the Makefile')

        self.abs_wrkdir = show_var('WRKDIR')
        self.determine_wrksrc()
        self.wrksrc_files = glob.glob(f'{self.abs_wrksrc}/**', recursive=True)
        self.wrksrc_dirs = glob.glob(f'{self.abs_wrksrc}/**/', recursive=True)

        self.makefile_lines = Lines.read_from(config.pkgdir + '/Makefile')

        self.adjust_configure()
        self.adjust_cmake()
        self.adjust_meson()
        self.adjust_gconf2_schemas()
        self.adjust_libtool()
        self.adjust_perl_module(url)
        self.adjust_python_module()
        self.adjust_cargo()
        self.adjust_pkg_config()
        self.adjust_po()
        self.adjust_use_languages()

        self.generate_adjusted_Makefile_lines(url).write_to(config.pkgdir + '/Makefile')

        if self.regenerate_distinfo:
            bmake('distinfo')


def main():
    global distname

    if not isfile('../../mk/bsd.pkg.mk'):
        sys.exit(f'ERROR: {sys.argv[0]} must be run from a package directory (.../pkgsrc/category/package).')

    try:
        opts, args = getopt.getopt(sys.argv[1:], 'v', ['verbose'])
        for (opt, optarg) in opts:
            print('opt', repr(opt))
            if opt in ('-v', '--verbose'):
                config.verbose = True
    except getopt.GetoptError:
        sys.exit(f'usage: {sys.argv[0]} [-v|--verbose] [URL]')

    if len(args) == 0:
        url = input('URL: ')
    else:
        url = args[0]

    extract_cookie = glob.glob('w*/.extract_done')
    if not extract_cookie or not isfile('Makefile'):
        generate_initial_package(url)
    else:
        distname = show_var('DISTNAME')

    Adjuster().adjust_package_from_extracted_distfiles(url)

    print('')
    print('Remember to run pkglint when you\'re done.')
    print('See ../../doc/pkgsrc.txt to get some help.')
    print('')


if __name__ == '__main__':
    main()
