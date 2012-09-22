# $NetBSD: Makefile,v 1.42 2012/09/22 13:48:19 ryoon Exp $
#

DISTNAME=		vlc-${VLC_VER}
PKGNAME=		vlc08-${VLC_VER}
VLC_VER=		0.8.6i
PKGREVISION=		25
CATEGORIES=		multimedia
MASTER_SITES=		http://download.videolan.org/pub/videolan/vlc/${VLC_VER}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Client

# Purposely not setting PREV_PKGPATH
SUPERSEDES=		vlc-0.8.*

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS=		vlc-[0-9]* vlc07-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-vcd
.endif

BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.0
BUILDLINK_API_DEPENDS.vcdimager+=	vcdimager>=0.7.20nb1
BUILDLINK_API_DEPENDS.libcdio+=		libcdio>=0.81

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

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/vlc/http/dialogs \
	share/vlc/http/images share/vlc/http/js \
	share/vlc/http/old share/vlc/http/old/admin \
	share/vlc/http/old/vlm share/vlc/http/requests \
	share/vlc/osdmenu/default share/vlc/osdmenu/default/selected \
	share/vlc/osdmenu/default/selection share/vlc/osdmenu/default/volume \
	share/vlc/osdmenu/dvd/selected share/vlc/osdmenu/dvd/volume \
	share/vlc/osdmenu/dvd/unselect share/vlc/osdmenu/dvd/selection \
	share/vlc/skins2 share/vlc/skins2/fonts

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

PLIST_VARS+=		cdda vcd fb
.if ${OPSYS} != "NetBSD"
PLIST.cdda=		yes
PLIST.vcd=		yes
.endif
.if ${OPSYS} == "Linux" && exists(/usr/include/linux/fb.h)
CONFIGURE_ARGS+=	--enable-fb
PLIST.fb=		yes
.else
CONFIGURE_ARGS+=	--disable-fb
.endif

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	x_libraries=${PREFIX}/lib
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
