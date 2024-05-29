# $NetBSD: Makefile,v 1.296 2024/05/29 16:33:48 adam Exp $

DISTNAME=		vlc-3.0.20
PKGREVISION=		8
CATEGORIES=		multimedia
MASTER_SITES=		https://download.videolan.org/pub/videolan/vlc/${PKGVERSION_NOREV}/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.videolan.org/
COMMENT=		VideoLAN media player and streaming server
LICENSE=		gnu-gpl-v2

CONFLICTS=		vlc07-[0-9]* vlc08-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake perl pkg-config
USE_TOOLS+=		autoreconf autoconf automake bison
USE_TOOLS+=		autopoint realpath msgfmt msgmerge xgettext

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-kde-solid=${PREFIX}/share/kde/apps/solid/actions
PTHREAD_OPTS+=		require
USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99
PLIST_VARS+=		altivec cdrom egl oss v4l2 x86simd

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_ENV+=		BUILDCC=${CC:Q}
CONFIGURE_ENV+=		LUAC=${PREFIX}/bin/luac5.2

# Avoid codec duplication with ffmpeg, etc

CONFIGURE_ARGS+=	--disable-aom
CONFIGURE_ARGS+=	--disable-archive
CONFIGURE_ARGS+=	--disable-aribsub
CONFIGURE_ARGS+=	--disable-aribb25
CONFIGURE_ARGS+=	--disable-caca
CONFIGURE_ARGS+=	--disable-chromaprint
CONFIGURE_ARGS+=	--disable-dav1d
CONFIGURE_ARGS+=	--disable-dc1394
CONFIGURE_ARGS+=	--disable-dv1394
CONFIGURE_ARGS+=	--disable-decklink
CONFIGURE_ARGS+=	--disable-dsm
CONFIGURE_ARGS+=	--disable-faad
CONFIGURE_ARGS+=	--disable-freerdp
CONFIGURE_ARGS+=	--disable-fluidlite
CONFIGURE_ARGS+=	--disable-goom
CONFIGURE_ARGS+=	--disable-gst-decode
CONFIGURE_ARGS+=	--disable-libplacebo
CONFIGURE_ARGS+=	--disable-libmpeg2
CONFIGURE_ARGS+=	--disable-live555
CONFIGURE_ARGS+=	--disable-mad
CONFIGURE_ARGS+=	--disable-mfx
CONFIGURE_ARGS+=	--disable-mmal
CONFIGURE_ARGS+=	--disable-ncurses
CONFIGURE_ARGS+=	--disable-nfs
CONFIGURE_ARGS+=	--disable-notify
CONFIGURE_ARGS+=	--disable-opencv
CONFIGURE_ARGS+=	--disable-projectm
CONFIGURE_ARGS+=	--disable-sdl-image
CONFIGURE_ARGS+=	--disable-secret
CONFIGURE_ARGS+=	--disable-sftp
CONFIGURE_ARGS+=	--disable-shine
CONFIGURE_ARGS+=	--disable-sid
CONFIGURE_ARGS+=	--disable-smbclient
CONFIGURE_ARGS+=	--disable-sndio
CONFIGURE_ARGS+=	--disable-soxr
CONFIGURE_ARGS+=	--disable-spatialaudio
CONFIGURE_ARGS+=	--disable-speex
CONFIGURE_ARGS+=	--disable-srt
CONFIGURE_ARGS+=	--disable-svg
CONFIGURE_ARGS+=	--disable-svgdec
CONFIGURE_ARGS+=	--disable-tiger
CONFIGURE_ARGS+=	--disable-twolame
CONFIGURE_ARGS+=	--disable-udev
CONFIGURE_ARGS+=	--disable-vpx
CONFIGURE_ARGS+=	--disable-vnc
CONFIGURE_ARGS+=	--disable-vsxu
CONFIGURE_ARGS+=	--disable-x264
CONFIGURE_ARGS+=	--disable-x26410b
CONFIGURE_ARGS+=	--disable-x265
CONFIGURE_ARGS+=	--disable-zvbi

# which platforms support OSSv4?
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS"
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

PLIST_VARS+=		neon
.if ${MACHINE_ARCH} == "earmv7hf"
PLIST.neon=		yes
CONFIGURE_ARGS+=	--enable-neon
.else
CONFIGURE_ARGS+=	--disable-neon
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

.include "../../graphics/MesaLib/features.mk"
.if ${MESALIB_SUPPORTS_EGL} == "yes"
PLIST.egl=		yes
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
#SUBST_FILES.oss+=	po/*.po
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=		fnt
SUBST_STAGE.fnt=	pre-configure
SUBST_SED.fnt=		-e "s,${ORIGFNT},${DEFAULT_FONT},"
SUBST_SED.fnt+=		-e "s,${ORIGMONOFNT},${DEFAULT_MONO_FONT},"
SUBST_FILES.fnt=	modules/text_renderer/freetype/platform_fonts.h
SUBST_MESSAGE.fnt=	Fixing hardcoded font paths.

# VLC embeds the build environment info to help debuging.
CHECK_WRKREF_SKIP=	lib/libvlccore.a \
			lib/libvlccore.so*

CPPFLAGS.SunOS+=	-D__EXTENSIONS__ -D_XOPEN_SOURCE=600
LDFLAGS.SunOS+=		-lsocket -lnsl

# The sed expression is a workaround for accepting NetBSD's libintl instead of gettext-lib
pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./bootstrap
	cd ${WRKSRC} && \
		${SED} -e 's/#define __GNU_GETTEXT_SUPPORTED_REVISION.*/#define __GNU_GETTEXT_SUPPORTED_REVISION(x) 1/' \
		       -e 's/#define __GNU_GETTEXT_SYMBOL_EXPRESSION.*/#define __GNU_GETTEXT_SYMBOL_EXPRESSION 0/' \
			configure > configure.sed && ${MV} configure.sed configure

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/musepack/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.0
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libbluray/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi0/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libkate/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/schroedinger/buildlink3.mk"
.include "../../net/libmicrodns/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
