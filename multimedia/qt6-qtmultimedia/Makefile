# $NetBSD: Makefile,v 1.17 2024/02/16 17:39:05 adam Exp $

DISTNAME=	qtmultimedia-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtmultimedia-${QTVERSION}
COMMENT=	Qt6 module with multimedia
CATEGORIES=	multimedia
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

# ALSA is experimental
CONFIGURE_ARGS+=	-no-alsa

.include "options.mk"

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Multimedia.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6MultimediaWidgets.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6SpatialAudio.pc

.include "../../graphics/qt6-qtquick3d/buildlink3.mk"
.include "../../graphics/qt6-qtshadertools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
