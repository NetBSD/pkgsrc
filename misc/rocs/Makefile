# $NetBSD: Makefile,v 1.39.2.1 2016/05/23 05:03:37 bsiegert Exp $

DISTNAME=	rocs-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	misc
COMMENT=	KDE graph theory IDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_ARGS+=	-DKDE4_BUILD_TESTS:BOOL=OFF

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang) || !empty(PKGSRC_COMPILER:Mgcc)
CXXFLAGS+=	-std=c++11
.endif

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/grantlee/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
