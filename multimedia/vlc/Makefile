# $NetBSD: Makefile,v 1.61.2.4 2008/12/04 17:37:19 tron Exp $
#

DISTNAME=		vlc-${VLC_VERSION}
CATEGORIES=		multimedia
MASTER_SITES=		http://download.videolan.org/pub/videolan/vlc/${VLC_VERSION}/
EXTRACT_SUFX=		.tar.bz2

VLC_VERSION=		0.9.8a

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		http://videolan.org/
COMMENT=		VLC media player and streaming server

CONFLICTS=		vlc07-[0-9]* vlc08-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config \
			aclocal autoconf automake autoheader
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
USE_LANGUAGES=		c99 c++
USE_DIRS+=		xdg-1.4
PLIST_VARS+=		x86simd altivec v4l2 vcd cdda

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-vcd
.else
PLIST.vcd=		yes
# This may need a closer look.
PLIST.cdda=		yes
.endif

BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.0
BUILDLINK_API_DEPENDS.vcdimager+=	vcdimager>=0.7.20nb1

CONFIGURE_ARGS+=	--disable-speex # needs unstable 1.1.x branch
CONFIGURE_ARGS+=	--disable-smb

CONFIGURE_ARGS+=	--enable-cddax \
			--enable-dvdread \
			--enable-flac \
			--enable-live555 \
			--enable-theora

# Build optimalized modules
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.x86simd=		yes
CONFIGURE_ARGS+=	--enable-mmx \
			--enable-sse
.endif
.if ${MACHINE_ARCH} == "powerpc"
PLIST.altivec=		yes
CONFIGURE_ARGS+=	--enable-altivec
.endif

# Enable when cleanly builds
.if exists(/usr/include/linux/videodev2.h) # || exists(/usr/include/sys/videoio.h)
CONFIGURE_ARGS+=	--enable-v4l2
PLIST.v4l2=		yes
.else
CONFIGURE_ARGS+=	--disable-v4l2
.endif

INSTALLATION_DIRS+=	${PREFIX}/share/vlc/http/dialogs \
			${PREFIX}/share/vlc/http/images \
			${PREFIX}/share/vlc/http/js \
			${PREFIX}/share/vlc/http/old \
			${PREFIX}/share/vlc/http/old/admin \
			${PREFIX}/share/vlc/http/old/vlm \
			${PREFIX}/share/vlc/http/requests \
			${PREFIX}/share/vlc/osdmenu/default \
			${PREFIX}/share/vlc/osdmenu/default/selected \
			${PREFIX}/share/vlc/osdmenu/default/selection \
			${PREFIX}/share/vlc/osdmenu/default/volume \
			${PREFIX}/share/vlc/osdmenu/dvd/selected \
			${PREFIX}/share/vlc/osdmenu/dvd/volume \
			${PREFIX}/share/vlc/osdmenu/dvd/unselect \
			${PREFIX}/share/vlc/osdmenu/dvd/selection \
			${PREFIX}/share/vlc/skins2 \
			${PREFIX}/share/vlc/skins2/fonts

pre-configure:
	cd ${WRKSRC} && autoreconf

pre-install:
	${INSTALL_DATA} ${WRKSRC}/doc/vlc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/vlc-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# Let's use dejavu-ttf as it has nice unicode support
#
ORIGFNT=		/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf
DEFAULT_FONT?=		${X11BASE}/lib/X11/fonts/TTF/DejaVuSans.ttf

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss+=	modules/access/v4l.c
SUBST_FILES.oss+=	modules/access/v4l2/v4l2.c
SUBST_FILES.oss+=	modules/audio_output/oss.c
SUBST_FILES.oss+=	modules/gui/pda/pda_interface.c
SUBST_FILES.oss+=	modules/gui/pda/pda.glade
SUBST_FILES.oss+=	test/libvlc/media_list.c
SUBST_FILES.oss+=	po/*.po
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=		fnt
SUBST_STAGE.fnt=	post-patch
SUBST_SED.fnt=		-e "s,${ORIGFNT},${DEFAULT_FONT},"
SUBST_FILES.fnt=	modules/misc/freetype.c
SUBST_MESSAGE.fnt=	Fixing hardcoded paths.

# VLC embeds the build environment info to help debuging
#
CHECK_WRKREF_SKIP=	lib/libvlccore.a \
			lib/libvlccore.so \
			lib/libvlccore.so.0 \
			lib/libvlccore.so.0.0.2

.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libdca/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../net/liblive/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
