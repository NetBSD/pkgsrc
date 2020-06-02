# $NetBSD: Makefile,v 1.115 2020/06/02 08:24:23 adam Exp $
#

DISTNAME=	avidemux_2.5.4
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	48
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/avidemux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fixounet.free.fr/avidemux/
COMMENT=	Graphical video editing program
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

GCC_REQD+=		3.0
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_CMAKE=		yes
CMAKE_ARG_PATH=		..
CONFIGURE_DIRS=		_build

CMAKE_ARGS+=		-DNO_ARTS=1
CMAKE_ARGS+=		-DUSE_SYSTEM_SPIDERMONKEY=1

LIBS+=			${LIBOSSAUDIO}

# make sure __STDC_CONSTANT_MACROS is set before <stdint.h> is
# pulled in the first time - for UINT64_C()
CFLAGS+=		-D__STDC_CONSTANT_MACROS

SUBST_CLASSES=		audio
SUBST_STAGE.audio=	pre-configure
SUBST_FILES.audio=	plugins/ADM_audioDevices/Oss/ADM_deviceoss.cpp
SUBST_SED.audio=	-e "s|\\/dev\\/dsp|${DEVOSSAUDIO}|g"
SUBST_MESSAGE.audio=	Fixing hardcoded audio device.

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

INSTALLATION_DIRS=	share/applications share/icons/hicolor/64x64/apps

pre-configure:
	${MKDIR} ${WRKSRC}/_build

post-configure:
	for manual in ${PATCHDIR}/manual-*; do \
		cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < $${manual}; \
	done

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
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
