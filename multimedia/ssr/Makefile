# $NetBSD: Makefile,v 1.51 2024/01/30 14:22:26 ryoon Exp $
#

DISTNAME=	ssr-0.4.2
PKGREVISION=	23
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=MaartenBaert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.maartenbaert.be/simplescreenrecorder/
COMMENT=	SimpleScreenRecorder, a screen recorder
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config bash:run
USE_LANGUAGES=	c c++

REPLACE_BASH=	scripts/ssr-glinject

CFLAGS.NetBSD+=	-DBSD
CFLAGS.SunOS+=	-DBSD

CMAKE_ARGS+=	-DWITH_QT5=on

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
