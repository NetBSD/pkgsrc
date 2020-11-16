# $NetBSD: Makefile,v 1.167 2020/11/16 12:15:28 nia Exp $

PKGREVISION=	7

.include "Makefile.common"

COMMENT=		Multimedia player library
LICENSE=		gnu-lgpl-v2

CONFLICTS+=		xine-xcb-[0-9]*

CONFIGURE_ARGS+=	--disable-v4l
CONFIGURE_ARGS+=	--disable-v4l2
CONFIGURE_ARGS+=	--disable-real-codecs
CONFIGURE_ARGS+=	--disable-mlib
CONFIGURE_ARGS+=	--disable-vaapi
CONFIGURE_ARGS+=	--disable-vidix
CONFIGURE_ARGS+=	--disable-w32dll
CONFIGURE_ARGS+=	--disable-xvmc

CONFIGURE_ARGS+=	--without-dav1d
CONFIGURE_ARGS+=	--without-esound

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/audio_out/audio_oss_out.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_SED.oss+=		-e "s,\"dsp\",\"audio\",g"
.endif
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

.if ${OPSYS} == "SunOS"
PLIST_VARS+=	oss
.  if ${OS_VERSION} == "5.11"
PLIST.oss=	yes
.  endif
.endif

CPPFLAGS.SunOS+=	-D__u32=uint32_t -DHAVE_SYSI86 -DHAVE_MMX_FALSE
LDFLAGS.SunOS+=		-lresolv

# xv video output seems to be broken. Make sure another gets used instead.
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}/xineplug_vo_out_xcbxv.*
	${RM} -f ${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}/xineplug_vo_out_xv.*

.include "options.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
#.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST_VARS+=	egl
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/features.mk"
.  if ${MESALIB_SUPPORTS_EGL} == "yes"
PLIST.egl=	yes
.  endif
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libbluray/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/vcdimager/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
