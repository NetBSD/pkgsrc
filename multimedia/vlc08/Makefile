# $NetBSD: Makefile,v 1.9 2006/07/22 04:46:17 rillig Exp $
#

DISTNAME=		vlc-${VLC_VER}
PKGREVISION=		4
CATEGORIES=		multimedia
MASTER_SITES=		http://download.videolan.org/pub/videolan/vlc/${VLC_VER}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Client

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
USE_LANGUAGES=		c c++

VLC_VER=		0.8.5

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=        --disable-vcd
.endif
BUILDLINK_API_DEPENDS.vcdimager+=	vcdimager>=0.7.20nb1
BUILDLINK_API_DEPENDS.ffmpeg+=	ffmpeg>=0.4.8nb1 # Postprocess fix

CONFIGURE_ARGS+=	--disable-skins2
CONFIGURE_ARGS+=	--disable-speex # needs unstable 1.1.x branch
CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--disable-gnomevfs
CONFIGURE_ARGS+=	--disable-gnutls
CONFIGURE_ARGS+=	--disable-smb
CONFIGURE_ARGS+=	--disable-dvbpsi
CONFIGURE_ARGS+=	--disable-mod
CONFIGURE_ARGS+=	--disable-mpc
CONFIGURE_ARGS+=	--disable-dts

CONFIGURE_ARGS+=	--with-ffmpeg-tree=${BUILDLINK_PREFIX.ffmpeg}/lib
CONFIGURE_ARGS+=	--with-ffmpeg-zlib
CONFIGURE_ARGS+=	--enable-cddax
CONFIGURE_ARGS+=	--enable-dvdread
CONFIGURE_ARGS+=	--enable-faad

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/http/dialogs
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/http/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/http/js
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/http/old
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/http/old/admin
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/http/old/vlm
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/http/requests
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/default
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/default/selected
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/default/selection
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/default/volume
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/dvd/selected
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/dvd/volume
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/dvd/unselect
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/osdmenu/dvd/selection
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/skins2
	${INSTALL_DATA_DIR} ${PREFIX}/share/vlc/skins2/fonts
	${INSTALL_DATA} ${WRKSRC}/doc/vlc.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/vlc-config.1 ${PREFIX}/man/man1

ORIGFNT=		/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf
DEFAULT_FONT?=		${X11BASE}/lib/X11/fonts/TTF/luximb.ttf

SUBST_CLASSES+=         oss fnt libav
SUBST_STAGE.oss=        post-patch
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss+=	modules/access/v4l/v4l.c
SUBST_FILES.oss+=	modules/audio_output/oss.c
SUBST_FILES.oss+=	modules/gui/pda/pda_interface.c
SUBST_FILES.oss+=	modules/gui/pda/pda.glade
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.
SUBST_STAGE.fnt=	post-patch
SUBST_SED.fnt=		-e "s,${ORIGFNT},${DEFAULT_FONT},"
SUBST_FILES.fnt=	modules/misc/freetype.c
SUBST_MESSAGE.fnt=	Fixing hardcoded paths.
SUBST_STAGE.libav=	post-patch
SUBST_FILES.libav=	configure
SUBST_SED.libav=	-e "s,libavcodec/libavcodec.a,libavcodec.a,g"

BUILDLINK_TRANSFORM.ffmpeg+=	-e "s,include/ffmpeg,include/,g"

.if ${OPSYS} == "NetBSD"
PLIST_SUBST+=		COND_CDDA="@comment "
PLIST_SUBST+=		COND_VCD="@comment "
.else
PLIST_SUBST+=		COND_CDDA=""
PLIST_SUBST+=		COND_VCD=""
.endif

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
