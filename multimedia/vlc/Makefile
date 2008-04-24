# $NetBSD: Makefile,v 1.50.2.1 2008/04/24 13:27:08 rtr Exp $
#

DISTNAME=		vlc-${VLC_VER}
VLC_VER=		0.8.6f
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
USE_DIRS+=		xdg-1.4

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-vcd
.endif

BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.0
BUILDLINK_API_DEPENDS.vcdimager+=	vcdimager>=0.7.20nb1

CONFIGURE_ARGS+=	--disable-speex # needs unstable 1.1.x branch
CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--disable-gnomevfs
CONFIGURE_ARGS+=	--disable-gnutls
CONFIGURE_ARGS+=	--with-ffmpeg-zlib
CONFIGURE_ARGS+=	--disable-smb
CONFIGURE_ARGS+=	--disable-mpc
CONFIGURE_ARGS+=	--disable-dts
CONFIGURE_ARGS+=	--enable-cddax
CONFIGURE_ARGS+=	--enable-dvdread
CONFIGURE_ARGS+=	--enable-flac

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

pre-install:
	${INSTALL_DATA} ${WRKSRC}/doc/vlc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/vlc-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

ORIGFNT=		/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf
DEFAULT_FONT?=		${X11BASE}/lib/X11/fonts/TTF/luximb.ttf

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss+=	modules/access/v4l/v4l.c
SUBST_FILES.oss+=	modules/audio_output/oss.c
SUBST_FILES.oss+=	modules/gui/pda/pda_interface.c
SUBST_FILES.oss+=	modules/gui/pda/pda.glade
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=         fnt
SUBST_STAGE.fnt=	post-patch
SUBST_SED.fnt=		-e "s,${ORIGFNT},${DEFAULT_FONT},"
SUBST_FILES.fnt=	modules/misc/freetype.c
SUBST_MESSAGE.fnt=	Fixing hardcoded paths.

.if ${OPSYS} == "NetBSD"
PLIST_SUBST+=		COND_CDDA="@comment "
PLIST_SUBST+=		COND_VCD="@comment "
.else
PLIST_SUBST+=		COND_CDDA=""
PLIST_SUBST+=		COND_VCD=""
.endif

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	x_libraries=${PREFIX}/lib
.endif

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/ffmpeg-devel/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
