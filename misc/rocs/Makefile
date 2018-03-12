# $NetBSD: Makefile,v 1.48 2018/03/12 11:17:09 wiz Exp $

DISTNAME=	rocs-${_KDE_VERSION}
PKGREVISION=	12
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
