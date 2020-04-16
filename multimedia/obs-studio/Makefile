# $NetBSD: Makefile,v 1.13 2020/04/16 22:48:25 ryoon Exp $

DISTNAME=	obs-studio-25.0.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=obsproject/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://obsproject.com/
COMMENT=	Video recording and live streaming software
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c gnu++11

CMAKE_ARGS+=	-DDISABLE_LIBFDK=BOOL:ON
CMAKE_ARGS+=	-DDISABLE_VLC=BOOL:ON

TOOL_DEPENDS+=	swig3>=3.0:../../devel/swig3

# Python 3 only
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "FreeBSD"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
# v4l2 fails to compile on netbsd
.if ${OPSYS} != "NetBSD"
.  include "../../graphics/libv4l/buildlink3.mk"
.endif
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../security/mbedtls/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
