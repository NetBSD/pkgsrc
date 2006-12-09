# $NetBSD: Makefile,v 1.41.2.1 2006/12/09 09:13:15 salo Exp $

.include "Makefile.common"

COMMENT=		Multimedia player library

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

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../sysutils/vcdimager-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
