# $NetBSD: url2pkg_test.py,v 1.3 2019/10/03 16:32:47 rillig Exp $

from url2pkg import *


def setup_function(_):
    config.pkgsrcdir = os.getenv('PKGSRCDIR')
    assert config.pkgsrcdir is not None
    os.chdir(config.pkgsrcdir + '/pkgtools/url2pkg')


def str_vars(vars: List[Var]) -> List[str]:
    return list(map(lambda var: var.name + var.op + var.value, vars))


def test_debug():
    """ Just ensure that the debug calls do not crash. """
    config.verbose = True
    try:
        debug('plain message')
        debug('list {0}', [1, 2, 3])
        debug('tuple {0}', (1, 2, 3))
        debug('cwd {0} env {1} cmd {2}', 'directory', {'VAR': 'value'}, 'command')
    finally:
        config.verbose = False


def test_aligned__empty():
    assert aligned([]) == []


def test_aligned__variables():
    vars = [
        Var('V', '=', 'value'),
        Var('LONG_NAME', '=', 'value # comment')
    ]
    lines = [
        'V=\t\tvalue',
        'LONG_NAME=\tvalue # comment',
        ''
    ]
    assert aligned(vars) == lines


def test_Lines_add_vars__simple():
    lines = Lines()

    lines.add_vars(
        Var("1", "=", "one"),
        Var("6", "=", "six"),
    )

    assert lines.lines == [
        "1=\tone",
        "6=\tsix",
        "",
    ]


def test_Lines_add_vars__alignment():
    lines = Lines()

    lines.add_vars(
        Var("short", "=", "value"),
        Var("long_name", "=", "value # comment"),
    )

    assert lines.lines == [
        "short=\t\tvalue",
        "long_name=\tvalue # comment",
        "",
    ]


def test_Lines_add_vars__operators():
    lines = Lines()

    lines.add_vars(
        Var("123456", "+=", "value"),
    )

    assert lines.lines == [
        "123456+=\tvalue",
        "",
    ]


def test_Lines_add_vars__empty():
    lines = Lines("# initial")

    lines.add_vars()

    # No empty line is added.
    assert lines.lines == ["# initial"]


def test_Lines_append__not_found():
    lines = Lines()

    lines.append("VARNAME", "value")

    assert lines.lines == []


def test_Lines_append__only_comment():
    lines = Lines("VARNAME=\t\t\t# none")

    lines.append("VARNAME", "value")

    assert lines.lines == ["VARNAME=\t\t\tvalue # none"]


def test_Lines_append__value_with_comment():
    lines = Lines("VARNAME=\tvalue # comment")

    lines.append("VARNAME", "appended")

    assert lines.lines == ["VARNAME=\tvalue appended # comment"]


def test_Lines_append__value_without_comment():
    lines = Lines("VARNAME+=\tvalue")

    assert lines.append("VARNAME", "appended")

    assert lines.lines == ["VARNAME+=\tvalue appended"]


def test_Lines_append__multiple_assignments():
    lines = Lines("VARNAME+=\tvalue1", "VARNAME+=\tvalue2")

    assert not lines.append("VARNAME", "appended")

    assert lines.lines == ["VARNAME+=\tvalue1", "VARNAME+=\tvalue2"]


def test_Lines_set__previously_with_comment():
    lines = Lines("LICENSE=\t# TODO: see mk/license.mk")

    assert lines.set("LICENSE", "${PERL5_LICENSE}")

    assert lines.lines == ["LICENSE=\t${PERL5_LICENSE}"]


def test_Lines_unique_varassign__commented_out_no_value():
    lines = Lines("#LICENSE=\t# TODO: see mk/license.mk")

    assert len(lines.all_varassigns('LICENSE')) == 1


def test_Lines_set__overwrite_comment_with_comment():
    lines = Lines("#LICENSE=\t# TODO: see mk/license.mk")

    assert len(lines.all_varassigns('LICENSE')) == 1
    assert lines.set("LICENSE", "${PERL5_LICENSE}")

    assert lines.lines == ["LICENSE=\t${PERL5_LICENSE}"]


def test_Lines_set__overwrite_commented_with_comment():
    lines = Lines("#LICENSE=\t# TODO: see mk/license.mk")

    assert lines.set("LICENSE", "${PERL5_LICENSE}")

    assert lines.lines == ["LICENSE=\t${PERL5_LICENSE}"]


def test_Lines_set__not_found():
    lines = Lines("OLD_VAR=\told value # old comment")

    assert not lines.set("NEW_VAR", "new value")

    assert lines.lines == ["OLD_VAR=\told value # old comment"]


def test_Lines_remove__not_found():
    lines = Lines('VAR=\tvalue')

    assert not lines.remove('VARIABLE')

    assert lines.lines == ['VAR=\tvalue']


def test_Lines_remove__found():
    lines = Lines('VAR=\tvalue')

    assert lines.remove('VAR')

    assert lines.lines == []


def test_Lines_remove__found_several_times():
    lines = Lines('VAR=\tvalue1', 'VAR=\tvalue2')

    assert not lines.remove('VAR')

    assert lines.lines == ['VAR=\tvalue1', 'VAR=\tvalue2']


def test_Lines_remove_if__different_name():
    lines = Lines('VAR=\tvalue')

    assert not lines.remove_if('VARIABLE', 'value')

    assert lines.lines == ['VAR=\tvalue']


def test_Lines_remove_if__different_value():
    lines = Lines('VAR=\tvalue')

    assert not lines.remove_if('VAR', 'something')

    assert lines.lines == ['VAR=\tvalue']


def test_Lines_remove_if__found():
    lines = Lines('VAR=\tvalue')

    assert lines.remove_if('VAR', 'value')

    assert lines.lines == []


def test_Lines_remove_if__multiple():
    lines = Lines('VAR=\tvalue', 'VAR=\tvalue')

    assert lines.remove_if('VAR', 'value')

    assert lines.lines == ['VAR=\tvalue']

    assert lines.remove_if('VAR', 'value')

    assert lines.lines == []


def test_Lines_index():
    lines = Lines("1", "2", "345")

    assert lines.index("1") == 0
    assert lines.index("2") == 1
    assert lines.index("345") == 2
    assert lines.index("4") == 2

    assert lines.index(r'^(\d\d)\d$') == 2
    assert lines.index(r"^\d\s\d$") == -1
    assert lines.index(r"(\d)") == 0


def test_Lines_get():
    lines = Lines(
        "VAR=value",
        "VAR=\tvalue # comment",
        "UNIQUE=\tunique"
    )

    assert lines.get("VAR") == ""  # too many values
    assert lines.get("ENOENT") == ""  # no value at all
    assert lines.get("UNIQUE") == "unique"


def test_generate_initial_package_Makefile_lines__GitHub_archive():
    url = "https://github.com/org/proj/archive/v1.0.0.tar.gz"

    lines = generate_initial_package_Makefile_lines(url)

    assert lines.lines == [
        "# $" + "NetBSD$",
        "",
        "GITHUB_PROJECT=\tproj",
        "DISTNAME=\tv1.0.0",
        "PKGNAME=\t${GITHUB_PROJECT}-${DISTNAME:S,^v,,}",
        "CATEGORIES=\tpkgtools",
        "MASTER_SITES=\t${MASTER_SITE_GITHUB:=org/}",
        "DIST_SUBDIR=\t${GITHUB_PROJECT}",
        "",
        "MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE",
        "HOMEPAGE=\thttps://github.com/org/proj/",
        "COMMENT=\tTODO: Short description of the package",
        "#LICENSE=\t# TODO: (see mk/license.mk)",
        "",
        "# url2pkg-marker (please do not remove this line.)",
        ".include \"../../mk/bsd.pkg.mk\""
    ]


def test_generate_initial_package_Makefile_lines__GitHub_release_containing_project_name():
    url = "https://github.com/org/proj/releases/download/1.0.0/proj.zip"

    lines = generate_initial_package_Makefile_lines(url)

    assert lines.lines == [
        "# $" + "NetBSD$",
        "",
        "GITHUB_PROJECT=\tproj",
        "DISTNAME=\tproj",
        "CATEGORIES=\tpkgtools",
        "MASTER_SITES=\t${MASTER_SITE_GITHUB:=org/}",
        "GITHUB_RELEASE=\t1.0.0",
        "EXTRACT_SUFX=\t.zip",
        "",
        "MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE",
        "HOMEPAGE=\thttps://github.com/org/proj/",
        "COMMENT=\tTODO: Short description of the package",
        "#LICENSE=\t# TODO: (see mk/license.mk)",
        "",
        "# url2pkg-marker (please do not remove this line.)",
        ".include \"../../mk/bsd.pkg.mk\""
    ]


def test_generate_initial_package_Makefile_lines__GitHub_release_not_containing_project_name():
    url = "https://github.com/org/proj/releases/download/1.0.0/data.zip"

    lines = generate_initial_package_Makefile_lines(url)

    assert lines.lines == [
        "# $" + "NetBSD$",
        "",
        "GITHUB_PROJECT=\tproj",
        "DISTNAME=\tdata",
        "CATEGORIES=\tpkgtools",
        "MASTER_SITES=\t${MASTER_SITE_GITHUB:=org/}",
        "GITHUB_RELEASE=\t1.0.0",
        "EXTRACT_SUFX=\t.zip",
        "DIST_SUBDIR=\t${GITHUB_PROJECT}",
        "",
        "MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE",
        "HOMEPAGE=\thttps://github.com/org/proj/",
        "COMMENT=\tTODO: Short description of the package",
        "#LICENSE=\t# TODO: (see mk/license.mk)",
        "",
        "# url2pkg-marker (please do not remove this line.)",
        ".include \"../../mk/bsd.pkg.mk\""
    ]


def test_generate_initial_package_Makefile_lines__distname_version_with_v():
    url = "https://cpan.example.org/Algorithm-CheckDigits-v1.3.2.tar.gz"

    lines = generate_initial_package_Makefile_lines(url)

    assert lines.lines == [
        "# $" + "NetBSD$",
        "",
        "DISTNAME=\tAlgorithm-CheckDigits-v1.3.2",
        "PKGNAME=\t${DISTNAME:S,-v,-,}",
        "CATEGORIES=\tpkgtools",
        "MASTER_SITES=\thttps://cpan.example.org/",
        "",
        "MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE",
        "HOMEPAGE=\thttps://cpan.example.org/",
        "COMMENT=\tTODO: Short description of the package",
        "#LICENSE=\t# TODO: (see mk/license.mk)",
        "",
        "# url2pkg-marker (please do not remove this line.)",
        ".include \"../../mk/bsd.pkg.mk\""
    ]


def test_Adjuster_read_dependencies():
    dep_lines = [
        "DEPENDS\tpackage>=80.0:../../pkgtools/pkglint",
        "DEPENDS\tpackage>=120.0:../../pkgtools/x11-links",
        "BUILD_DEPENDS\turl2pkg>=1.0",
        "TEST_DEPENDS\tpkglint",
        "A line that is not a dependency at all",
        "",
        "var\tHOMEPAGE\thttps://homepage.example.org/"
        ""
    ]
    env = {"URL2PKG_DEPENDENCIES": '\n'.join(dep_lines)}
    cmd = "printf '%s\n' \"$URL2PKG_DEPENDENCIES\""

    adjuster = Adjuster()
    adjuster.read_dependencies(cmd, env, '.', '')

    assert os.getenv('URL2PKG_DEPENDENCIES') is None

    assert adjuster.depends == [
        "package>=80.0:../../pkgtools/pkglint"
    ]
    assert adjuster.bl3_lines == [
        'BUILDLINK_API_DEPENDS.x11-links+=\tx11-links>=120.0',
        ".include \"../../pkgtools/x11-links/buildlink3.mk\""
    ]
    assert adjuster.build_depends == [
        "url2pkg>=1.0:../../pkgtools/url2pkg"
    ]
    assert adjuster.test_depends == [
        "pkglint>=0:../../pkgtools/pkglint"
    ]
    assert adjuster.update_vars == {
        'HOMEPAGE': 'https://homepage.example.org/'
    }


def test_Adjuster_generate_adjusted_Makefile_lines():
    adjuster = Adjuster()
    adjuster.makefile_lines = Lines(
        "# before 1",
        "# before 2",
        "# url2pkg-marker",
        "# after 1",
        "# after 2"
    )

    lines = adjuster.generate_adjusted_Makefile_lines("https://example.org/pkgname-1.0.tar.gz")

    assert lines.lines == [
        "# before 1",
        "# before 2",
        "# after 1",
        "# after 2"
    ]


def test_Adjuster_generate_adjusted_Makefile_lines__dependencies():
    adjuster = Adjuster()
    adjuster.makefile_lines.add(
        "# $" + "NetBSD$",
        "",
        "# url2pkg-marker",
        ".include \"../../mk/bsd.pkg.mk\""
    )

    # some dependencies whose directory will not be found
    adjuster.add_dependency("DEPENDS", "depends", ">=5.0", "../../devel/depends")
    adjuster.add_dependency("TOOL_DEPENDS", "tool-depends", ">=6.0", "../../devel/tool-depends")
    adjuster.add_dependency("BUILD_DEPENDS", "build-depends", ">=7.0", "../../devel/build-depends")
    adjuster.add_dependency("TEST_DEPENDS", "test-depends", ">=8.0", "../../devel/test-depends")
    # some dependencies whose directory is explicitly given
    adjuster.depends.append("depends>=11.0:../../devel/depends")
    adjuster.build_depends.append("build-depends>=12.0:../../devel/build-depends")
    adjuster.test_depends.append("test-depends>=13.0:../../devel/test-depends")

    lines = adjuster.generate_adjusted_Makefile_lines("https://example.org/pkgname-1.0.tar.gz")

    assert lines.lines == [
        "# $" + "NetBSD$",
        "",
        "# TODO: dependency TOOL_DEPENDS # TODO: tool-depends>=6.0",
        "",
        "BUILD_DEPENDS+=\t# TODO: build-depends>=7.0",
        "BUILD_DEPENDS+=\tbuild-depends>=12.0:../../devel/build-depends",
        "DEPENDS+=\t# TODO: depends>=5.0",
        "DEPENDS+=\tdepends>=11.0:../../devel/depends",
        "TEST_DEPENDS+=\t# TODO: test-depends>=8.0",
        "TEST_DEPENDS+=\ttest-depends>=13.0:../../devel/test-depends",
        "",
        ".include \"../../mk/bsd.pkg.mk\""
    ]


def test_Adjuster_add_dependency__buildlink():
    adjuster = Adjuster()
    adjuster.makefile_lines.add('# url2pkg-marker')

    adjuster.add_dependency('BUILD_DEPENDS', 'libusb', '>=2019', '../../devel/libusb')

    lines = adjuster.generate_adjusted_Makefile_lines('https://example.org/distfile-1.0.zip')

    assert lines.lines == [
        'BUILDLINK_DEPENDS.libusb+=\tbuild',
        'BUILDLINK_API_DEPENDS.libusb+=\tlibusb>=2019',
        '.include "../../devel/libusb/buildlink3.mk"',
    ]


def test_Adjuster_adjust_configure__not_found(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrksrc = str(tmp_path)

    adjuster.adjust_configure()

    assert adjuster.build_vars == []


def test_Adjuster_adjust_configure__GNU_configure(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrksrc = str(tmp_path)
    (tmp_path / 'configure').write_text('# Free Software Foundation\n')

    adjuster.adjust_configure()

    assert str_vars(adjuster.build_vars) == [
        'GNU_CONFIGURE=yes',
    ]


def test_Adjuster_adjust_configure__other_configure(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrksrc = str(tmp_path)
    (tmp_path / 'configure').write_text('# A generic configure script\n')

    adjuster.adjust_configure()

    assert str_vars(adjuster.build_vars) == [
        'HAS_CONFIGURE=yes',
    ]


def test_Adjuster_adjust_cargo__not_found(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrksrc = str(tmp_path)

    adjuster.adjust_cargo()

    assert str_vars(adjuster.build_vars) == []


def test_Adjuster_adjust_cargo__found(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrksrc = str(tmp_path)
    (tmp_path / 'Cargo.lock').write_text('"checksum cargo-package-name cargo-package-version 1234"')

    adjuster.adjust_cargo()

    assert str_vars(adjuster.build_vars) == [
        'CARGO_CRATE_DEPENDS+=cargo-package-name-cargo-package-version',
    ]


def test_Adjuster_adjust_po__not_found():
    adjuster = Adjuster()

    adjuster.adjust_po()

    assert adjuster.build_vars == []


def test_Adjuster_adjust_po__found():
    adjuster = Adjuster()
    adjuster.wrksrc_files = ['share/locale/de.mo']

    adjuster.adjust_po()

    assert str_vars(adjuster.build_vars) == [
        'USE_PKGLOCALEDIR=yes'
    ]


def test_Adjuster_adjust_use_languages__none():
    adjuster = Adjuster()

    adjuster.adjust_use_languages()

    assert str_vars(adjuster.build_vars) == [
        'USE_LANGUAGES=# none'
    ]


def test_Adjuster_adjust_use_languages__c():
    adjuster = Adjuster()
    adjuster.wrksrc_files = ['main.c']

    adjuster.adjust_use_languages()

    assert str_vars(adjuster.build_vars) == []


def test_Adjuster_adjust_use_languages__c_in_subdir():
    adjuster = Adjuster()
    adjuster.wrksrc_files = ['subdir/main.c']

    adjuster.adjust_use_languages()

    assert str_vars(adjuster.build_vars) == []


def test_Adjuster_adjust_use_languages__cplusplus_in_subdir():
    adjuster = Adjuster()
    adjuster.wrksrc_files = ['subdir/main.cpp']

    adjuster.adjust_use_languages()

    assert str_vars(adjuster.build_vars) == [
        'USE_LANGUAGES=c++'
    ]


def test_Adjuster_adjust_use_languages__cplusplus_and_fortran():
    adjuster = Adjuster()
    adjuster.wrksrc_files = ['subdir/main.cpp', 'main.f']

    adjuster.adjust_use_languages()

    assert str_vars(adjuster.build_vars) == [
        'USE_LANGUAGES=c++ fortran'
    ]


def test_Adjuster_adjust_pkg_config__none():
    adjuster = Adjuster()

    adjuster.adjust_pkg_config()

    assert str_vars(adjuster.build_vars) == []
    assert str_vars(adjuster.extra_vars) == []


def test_Adjuster_adjust_pkg_config__pc_in():
    adjuster = Adjuster()
    adjuster.wrksrc_files = ['library.pc.in']

    adjuster.adjust_pkg_config()

    assert str_vars(adjuster.build_vars) == ['USE_TOOLS+=pkg-config']
    assert str_vars(adjuster.extra_vars) == ['PKGCONFIG_OVERRIDE+=library.pc.in']


def test_Adjuster_adjust_pkg_config__uninstalled_pc_in():
    adjuster = Adjuster()
    adjuster.wrksrc_files = ['library-uninstalled.pc.in']

    adjuster.adjust_pkg_config()

    assert str_vars(adjuster.build_vars) == []
    assert str_vars(adjuster.extra_vars) == []


def test_Adjuster_adjust_pkg_config__both():
    adjuster = Adjuster()
    adjuster.wrksrc_files = [
        'library.pc.in',
        'library-uninstalled.pc.in'
    ]

    adjuster.adjust_pkg_config()

    assert str_vars(adjuster.build_vars) == ['USE_TOOLS+=pkg-config']
    assert str_vars(adjuster.extra_vars) == ['PKGCONFIG_OVERRIDE+=library.pc.in']


def test_Adjuster__adjust_homepage():
    url = 'https://dummy.example.org/package-1.0.tar.gz'
    adjuster = Adjuster()
    adjuster.makefile_lines = generate_initial_package_Makefile_lines(url)
    adjuster.update_vars['HOMEPAGE'] = 'https://example.org/'
    adjuster.depends.append('dependency>=0:../../category/dependency')
    adjuster.todos.append('Run pkglint')

    lines = adjuster.generate_adjusted_Makefile_lines(url)

    assert lines.lines == [
        '# $' + 'NetBSD$',
        '',
        'DISTNAME=\tpackage-1.0',
        'PKGNAME=\t${DISTNAME}',
        'CATEGORIES=\tpkgtools',
        'MASTER_SITES=\thttps://dummy.example.org/',
        '',
        'MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE',
        'HOMEPAGE=\thttps://example.org/',
        'COMMENT=\tTODO: Short description of the package',
        '#LICENSE=\t# TODO: (see mk/license.mk)',
        '',
        '# TODO: Run pkglint',
        '',
        'DEPENDS+=\tdependency>=0:../../category/dependency',
        '',
        '.include "../../mk/bsd.pkg.mk"'
    ]


def test_Adjuster_determine_wrksrc__no_files(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrkdir = str(tmp_path)

    adjuster.determine_wrksrc()

    assert adjuster.abs_wrksrc == adjuster.abs_wrkdir


def test_Adjuster_determine_wrksrc__single_dir(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrkdir = str(tmp_path)
    (tmp_path / 'subdir').mkdir()

    adjuster.determine_wrksrc()

    assert adjuster.abs_wrksrc == adjuster.abs_wrkdir + '/subdir'


def test_Adjuster_determine_wrksrc__several_dirs(tmp_path):
    adjuster = Adjuster()
    adjuster.abs_wrkdir = str(tmp_path)
    (tmp_path / 'subdir1').mkdir()
    (tmp_path / 'subdir2').mkdir()

    adjuster.determine_wrksrc()

    assert adjuster.abs_wrksrc == adjuster.abs_wrkdir
    assert str_vars(adjuster.build_vars) == [
        'WRKSRC=${WRKDIR} # More than one possibility -- please check manually.'
    ]


def test_Adjuster_adjust_package_from_extracted_distfiles__empty_wrkdir(tmp_path):
    pkgdir = tmp_path
    wrkdir = tmp_path / 'wrkdir'
    fake = '''\
#! /bin/sh
case $* in
("show-var VARNAME=WRKDIR") echo '%s' ;;
(*) "unknown: $*" ;;
esac
''' % str(wrkdir)
    config.pkgdir = str(tmp_path)
    wrkdir.mkdir()
    url = 'https://example.org/distfile-1.0.zip'
    adjuster = Adjuster()
    adjuster.abs_wrkdir = str(wrkdir)
    (pkgdir / 'Makefile').write_text('# url2pkg-marker\n')
    fake_path = (tmp_path / "fake")
    fake_path.write_text(fake)
    fake_path.chmod(0o755)

    prev_make = config.make
    config.make = fake_path
    try:
        adjuster.adjust_package_from_extracted_distfiles(url)
    finally:
        config.make = prev_make

    assert adjuster.generate_adjusted_Makefile_lines(url).lines == [
        'WRKSRC=\t\t${WRKDIR}',
        'USE_LANGUAGES=\t# none',
        '',
    ]
