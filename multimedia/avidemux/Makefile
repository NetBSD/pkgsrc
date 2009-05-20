# $NetBSD: Makefile,v 1.55 2009/05/20 00:58:24 wiz Exp $
#

DISTNAME=	avidemux_2.4.4
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/avidemux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fixounet.free.fr/avidemux/
COMMENT=	Graphical video editing program

PKG_DESTDIR_SUPPORT=	user-destdir

GCC_REQD+=		3.0
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config
USE_CMAKE=		yes
USE_DIRS+=		xdg-1.4

CMAKE_ARGS+=		-DNO_ARTS=1

LIBS+=			${LIBOSSAUDIO}

SUBST_CLASSES=		audio
SUBST_STAGE.audio=	post-patch
SUBST_FILES.audio=	avidemux/ADM_audiodevice/ADM_deviceoss.cpp
SUBST_SED.audio=	-e "s|\\/dev\\/dsp|${DEVOSSAUDIO}|g"
SUBST_MESSAGE.audio=	Fixing hardcoded audio device.

INSTALLATION_DIRS=	share/applications share/icons/hicolor/64x64/apps

post-install:
	${INSTALL_DATA} ${WRKSRC}/avidemux2.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/avidemux2.desktop
	${INSTALL_DATA} ${WRKSRC}/avidemux_icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/64x64/apps/avidemux.png

.include "options.mk"

.include "../../audio/faac/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
