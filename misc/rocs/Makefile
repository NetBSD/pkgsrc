# $NetBSD: Makefile,v 1.52 2019/07/01 04:08:36 ryoon Exp $

DISTNAME=	rocs-${_KDE_VERSION}
PKGREVISION=	16
CATEGORIES=	misc
COMMENT=	KDE graph theory IDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_LANGUAGES+=	c++11

CMAKE_ARGS+=	-DKDE4_BUILD_TESTS:BOOL=OFF

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/grantlee/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
