# $NetBSD: Makefile,v 1.5 2004/04/19 18:15:00 drochner Exp $
#

DISTNAME=		vlc-0.7.1
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		http://download.videolan.org/pub/videolan/vlc/0.7.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Client

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

SUBST_CLASSES+=		oss
SUBST_SED.oss+=		-e 's|/dev/dsp|${DEVOSSAUDIO}|'
SUBST_STAGE.oss=	post-patch
SUBST_MESSAGE.oss=	"patching hardcoded /dev/dsp."
SUBST_FILES.oss+=	modules/access/v4l/v4l.c
SUBST_FILES.oss+=	modules/audio_output/oss.c
SUBST_FILES.oss+=	modules/gui/pda/pda_interface.c
SUBST_FILES.oss+=	modules/gui/pda/pda.glade
SUBST_FILES.oss+=	modules/gui/wxwindows/v4l.cpp

.include "../../mk/bsd.prefs.mk"

# XXX FIXME
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=        --disable-vcd
CONFIGURE_ARGS+=	--disable-skins2
.endif
BUILDLINK_DEPENDS.vcdimager+= vcdimager>=0.7.20nb1

CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--enable-dvb

# XXX FIXME
CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--disable-mkv
CONFIGURE_ARGS+=	--disable-faad
CONFIGURE_ARGS+=	--disable-ffmpeg

CONFIGURE_ARGS+=	--enable-flac
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--disable-qt
CONFIGURE_ARGS+=	--disable-kde
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-gtk

WITH_DVDCSS?=		NO
BUILD_DEFS+=		WITH_DVDCSS

.if !empty(WITH_DVDCSS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-dvdcss="${BUILDLINK_PREFIX.libdvdcss}"
.include "../../multimedia/libdvdcss/buildlink3.mk"
PLIST_SUBST+=	DVDCSS=
.else
CONFIGURE_ARGS+=	--disable-dvd
PLIST_SUBST+=	DVDCSS="@comment "
.endif

#.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../graphics/ffmpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../sysutils/vcdimager-devel/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
