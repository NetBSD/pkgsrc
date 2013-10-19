# $NetBSD: Makefile,v 1.64 2013/10/19 09:07:03 adam Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	9
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DBUILD_kmtrace:BOOL=OFF

# disable for the moment till sort out -ldl
CMAKE_ARGS+=	-DBUILD_kstartperf:BOOL=OFF

REPLACE_BASH+= \
	kde-dev-scripts/create_makefile \
	kde-dev-scripts/create_svnignore \
	kde-dev-scripts/makeobj \
	kde-dev-scripts/package_crystalsvg \
	kde-dev-scripts/svnversions

REPLACE_PERL+= \
	kcachegrind/converters/dprof2calltree \
	kcachegrind/converters/memprof2calltree \
	kcachegrind/converters/op2calltree \
	kdesdk-kioslaves/perldoc/pod2html.pl \
	kde-dev-scripts/colorcvs \
	kde-dev-scripts/colorsvn \
	kde-dev-scripts/cvs-clean \
	kde-dev-scripts/cvsblame \
	kde-dev-scripts/cvscheck \
	kde-dev-scripts/cvslastchange \
	kde-dev-scripts/cxxmetric \
	kde-dev-scripts/extend_dmalloc \
	kde-dev-scripts/extractattr \
	kde-dev-scripts/extractqml \
	kde-dev-scripts/extractrc \
	kde-dev-scripts/fixheaders \
	kde-dev-scripts/fixkdeincludes \
	kde-dev-scripts/fixuifiles \
	kde-dev-scripts/generate_string_table.pl \
	kde-dev-scripts/includemocs \
	kde-dev-scripts/kde-spellcheck.pl \
	kde-dev-scripts/kdemangen.pl \
	kde-dev-scripts/kdesrc-build \
	kde-dev-scripts/krazy-licensecheck \
	kde-dev-scripts/noncvslist \
	kde-dev-scripts/png2mng.pl \
	kde-dev-scripts/rc2kcfgxt.pl \
	kde-dev-scripts/svn-clean \
	kde-dev-scripts/svnintegrate \
	kde-dev-scripts/svnlastchange \
	umbrello/umbrello/headings/heading.pm

# REPLACE_PHP+= kcachegrind/converters/pprof2calltree
SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	kcachegrind/converters/pprof2calltree
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

REPLACE_PYTHON+= \
	kcachegrind/converters/hotshot2calltree \
	lokalize/scripts/xliffmerge.py \
	kde-dev-scripts/kde-systemsettings-tree.py \
	kde-dev-scripts/kde_generate_export_header \
	kde-dev-scripts/kdelnk2desktop.py \
	kde-dev-scripts/rename_source_files \
	kde-dev-scripts/zonetab2pot.py \
	umbrello/umbrello/headings/heading.py

REPLACE_RUBY+= \
	umbrello/umbrello/headings/heading.rb

REPLACE_SH+= \
	kde-dev-scripts/build-progress.sh \
	kde-dev-scripts/cvsaddcurrentdir

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

USE_TOOLS+=	gmake bash:run

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/ruby/replace.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
