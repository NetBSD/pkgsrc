# $NetBSD: Makefile,v 1.3 2009/12/15 21:40:01 joerg Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DBUILD_kmtrace:BOOL=OFF

# disable for the moment till sort out -ldl
CMAKE_ARGS+=	-DBUILD_kstartperf:BOOL=OFF

REPLACE_PERL+= \
	scripts/cxxmetric \
	scripts/fixkdeincludes \
	scripts/fixuifiles \
	scripts/kdesvn-build \
	scripts/krazy-licensecheck \
	scripts/png2mng.pl \
	scripts/svnintegrate \
	kioslave/perldoc/pod2html.pl \
	kcachegrind/converters/dprof2calltree \
	kcachegrind/converters/memprof2calltree \
	kcachegrind/converters/op2calltree \
	cervisia/cervisia-change_repos_list.pl \
	cervisia/cervisia-normalize_cvsroot.pl \
	cervisia/change_colors.pl

REPLACE_SH+= \
	scripts/build-progress.sh \
	scripts/cvsaddcurrentdir

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

USE_TOOLS+=	gmake

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/libiberty/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
