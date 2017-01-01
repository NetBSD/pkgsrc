# $NetBSD: Makefile,v 1.43 2017/01/01 16:06:29 adam Exp $

DISTNAME=	rocs-${_KDE_VERSION}
PKGREVISION=	8
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
