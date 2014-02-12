# $NetBSD: Makefile,v 1.120 2014/02/12 23:18:18 tron Exp $

.include "Makefile.common"

PKGREVISION=		1

COMMENT=		Multimedia player library

CONFLICTS+=		xine-xcb-[0-9]*

CONFIGURE_ARGS+=	--disable-v4l
CONFIGURE_ARGS+=	--disable-v4l2
CONFIGURE_ARGS+=	--disable-real-codecs
CONFIGURE_ARGS+=	--disable-aalib
CONFIGURE_ARGS+=	--disable-mlib

BUILDLINK_API_DEPENDS.vcdimager+= vcdimager>=0.7.20nb1

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/audio_out/audio_oss_out.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_SED.oss+=		-e "s,\"dsp\",\"audio\",g"
.endif
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=		w32path
SUBST_STAGE.w32path=	post-patch
SUBST_FILES.w32path=	src/libw32dll/common.c
SUBST_SED.w32path=	-e "s,@W32PATH@,${PREFIX}/lib/win32,"
SUBST_MESSAGE.w32path=	Fixing win32 dll path.

# Needed to fix build problems under, at least, NetBSD/amd64.
BUILDLINK_API_DEPENDS.libcdio+=	libcdio>=0.75

.if ${OPSYS} == "SunOS"
PLIST_VARS+=	oss
.if ${OS_VERSION} == "5.11"
PLIST.oss=	yes
.endif
.endif

CPPFLAGS.SunOS+=	-D__u32=uint32_t -DHAVE_SYSI86
LDFLAGS.SunOS+=		-lresolv

# flac is supported internally; don't know what the plugin is good for
#.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
# these could be options or (better) extra plugin packages
#.include "../../devel/SDL/buildlink3.mk"
#.include "../../graphics/ImageMagick/buildlink3.mk"
#.include "../../graphics/Mesa/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-opengl
#.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../sysutils/vcdimager-devel/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
