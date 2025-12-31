# $NetBSD: Makefile,v 1.38 2025/12/31 09:59:08 tnn Exp $

DISTNAME=	qtmultimedia-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtmultimedia-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module with multimedia
CATEGORIES=	multimedia
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

# ALSA is experimental
CONFIGURE_ARGS+=	-no-alsa

SUBST_CLASSES+=			AvFoundation
SUBST_STAGE.AvFoundation=	pre-configure
SUBST_MESSAGE.AvFoundation=	Fixing build on case-sensitive filesystem
SUBST_SED.AvFoundation=		-e 's,AvFoundation/AVFoundation.h,AVFoundation/AVFoundation.h,g'
SUBST_FILES.AvFoundation=	src/plugins/multimedia/darwin/*.h
SUBST_FILES.AvFoundation+=	src/plugins/multimedia/darwin/*/*.h

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
