# $NetBSD: Makefile,v 1.80 2019/08/11 13:22:04 wiz Exp $

DISTNAME=		vlc-${VLC_VERSION}
PKGNAME=		${DISTNAME:S/vlc/vlc2/}
PKGREVISION=		9
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vlc/}
MASTER_SITES+=		http://download.videolan.org/pub/videolan/vlc/${VLC_VERSION}/
EXTRACT_SUFX=		.tar.xz

VLC_VERSION=		2.2.6

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VLC media player and streaming server
LICENSE=		gnu-gpl-v2

CONFLICTS=		vlc07-[0-9]* vlc08-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-kde-solid=${PREFIX}/share/kde/apps/solid/actions
PTHREAD_OPTS+=		require
USE_LANGUAGES=		c99 c++
PLIST_VARS+=		altivec cdrom oss v4l2 x86simd

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.0

CONFIGURE_ARGS+=	--enable-dvdread
CONFIGURE_ARGS+=	--enable-flac
CONFIGURE_ARGS+=	--enable-theora
CONFIGURE_ARGS+=	--disable-bluray
CONFIGURE_ARGS+=	--disable-bonjour
CONFIGURE_ARGS+=	--disable-caca
CONFIGURE_ARGS+=	--disable-chromaprint
CONFIGURE_ARGS+=	--disable-dc1394
CONFIGURE_ARGS+=	--disable-decklink
CONFIGURE_ARGS+=	--disable-dv1394
CONFIGURE_ARGS+=	--disable-freerdp
CONFIGURE_ARGS+=	--disable-goom
CONFIGURE_ARGS+=	--disable-gst-decode
CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-mfx
CONFIGURE_ARGS+=	--disable-mmal-codec
CONFIGURE_ARGS+=	--disable-notify
CONFIGURE_ARGS+=	--disable-opencv
CONFIGURE_ARGS+=	--disable-projectm
CONFIGURE_ARGS+=	--disable-samplerate
CONFIGURE_ARGS+=	--disable-sftp
CONFIGURE_ARGS+=	--disable-shine
CONFIGURE_ARGS+=	--disable-sid
CONFIGURE_ARGS+=	--disable-smbclient
CONFIGURE_ARGS+=	--disable-twolame
CONFIGURE_ARGS+=	--disable-udev
CONFIGURE_ARGS+=	--disable-vnc
CONFIGURE_ARGS+=	--disable-vsxu
CONFIGURE_ARGS+=	--disable-zvbi

CFLAGS+=		-fPIC
CXXFLAGS+=		-fPIC

# which platforms support OSSv4?
.if ${MACHINE_PLATFORM:MNetBSD-[789]*-*}
PLIST.oss=		yes
.include "../../mk/oss.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

# Build optimized modules
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.x86simd=		yes
CONFIGURE_ARGS+=	--enable-mmx \
			--enable-sse
.endif
.if ${MACHINE_ARCH} == "powerpc"
PLIST.altivec=		yes
CONFIGURE_ARGS+=	--enable-altivec
.endif

# SunOS cdio interface is unsupported
.if ${OPSYS} != "SunOS"
PLIST.cdrom=		yes
.endif

# Enable when cleanly builds
.if exists(/usr/include/linux/videodev2.h) # || exists(/usr/include/sys/videoio.h)
CONFIGURE_ARGS+=	--enable-v4l2
PLIST.v4l2=		yes
.else
CONFIGURE_ARGS+=	--disable-v4l2
.endif

INSTALLATION_DIRS+=	share/vlc/http/dialogs share/vlc/http/images \
			share/vlc/http/js share/vlc/http/old \
			share/vlc/http/old/admin share/vlc/http/old/vlm \
			share/vlc/http/requests share/vlc/osdmenu/default \
			share/vlc/osdmenu/default/selected \
			share/vlc/osdmenu/default/selection \
			share/vlc/osdmenu/default/volume \
			share/vlc/osdmenu/dvd/selected \
			share/vlc/osdmenu/dvd/volume \
			share/vlc/osdmenu/dvd/unselect \
			share/vlc/osdmenu/dvd/selection \
			share/vlc/skins2/fonts \
			${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/vlc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# Let's use dejavu-ttf as it has nice unicode support
#
ORIGFNT=		/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf
ORIGMONOFNT=		/usr/share/fonts/truetype/freefont/FreeMono.ttf
DEFAULT_FONT?=		${PREFIX}/share/fonts/X11/TTF/DejaVuSans.ttf
DEFAULT_MONO_FONT?=	${PREFIX}/share/fonts/X11/TTF/DejaVuSansMono.ttf
DEPENDS+=		dejavu-ttf>=2.26:../../fonts/dejavu-ttf

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss+=	modules/access/oss.c
SUBST_FILES.oss+=	modules/audio_output/oss.c
SUBST_FILES.oss+=	po/*.po
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=		fnt
SUBST_STAGE.fnt=	pre-configure
SUBST_SED.fnt=		-e "s,${ORIGFNT},${DEFAULT_FONT},"
SUBST_SED.fnt+=		-e "s,${ORIGMONOFNT},${DEFAULT_MONO_FONT},"
SUBST_FILES.fnt=	modules/text_renderer/platform_fonts.h
SUBST_MESSAGE.fnt=	Fixing hardcoded font paths.

# VLC embeds the build environment info to help debuging.
CHECK_WRKREF_SKIP=	lib/libvlccore.a \
			lib/libvlccore.so*

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../multimedia/libkate/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/musepack/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"

.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi0/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/schroedinger/buildlink3.mk"
# libX11 should be built with xcb enabled
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.3.5
.include "../../x11/libX11/buildlink3.mk"
# needs x264_encoder_delayed_frames
BUILDLINK_API_DEPENDS.x264-devel+= x264-devel>=20100201
.include "../../multimedia/x264-devel/buildlink3.mk"
#.include "../../lang/lua/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.if "${OPSYS}" == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
