# $NetBSD: Makefile,v 1.43 2012/09/15 10:04:11 obache Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	4
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
	scripts/create_makefile \
	scripts/create_svnignore \
	scripts/makeobj \
	scripts/package_crystalsvg \
	scripts/svnversions

REPLACE_PERL+= \
	cervisia/cervisia-change_repos_list.pl \
	cervisia/cervisia-normalize_cvsroot.pl \
	cervisia/change_colors.pl \
	kcachegrind/converters/dprof2calltree \
	kcachegrind/converters/memprof2calltree \
	kcachegrind/converters/op2calltree \
	kioslave/perldoc/pod2html.pl \
	scripts/colorcvs \
	scripts/colorsvn \
	scripts/cvs-clean \
	scripts/cvsblame \
	scripts/cvscheck \
	scripts/cvslastchange \
	scripts/cxxmetric \
	scripts/extend_dmalloc \
	scripts/extractattr \
	scripts/extractqml \
	scripts/extractrc \
	scripts/fixheaders \
	scripts/fixkdeincludes \
	scripts/fixuifiles \
	scripts/generate_string_table.pl \
	scripts/includemocs \
	scripts/kde-spellcheck.pl \
	scripts/kdemangen.pl \
	scripts/kdesrc-build \
	scripts/krazy-licensecheck \
	scripts/noncvslist \
	scripts/png2mng.pl \
	scripts/rc2kcfgxt.pl \
	scripts/svn-clean \
	scripts/svnintegrate \
	scripts/svnlastchange \
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
	scripts/kde-systemsettings-tree.py \
	scripts/kde_generate_export_header \
	scripts/kdelnk2desktop.py \
	scripts/rename_source_files \
	scripts/zonetab2pot.py \
	umbrello/umbrello/headings/heading.py

REPLACE_RUBY+= \
	umbrello/umbrello/headings/heading.rb

REPLACE_SH+= \
	scripts/build-progress.sh \
	scripts/cvsaddcurrentdir

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

USE_TOOLS+=	gmake bash:run

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

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
