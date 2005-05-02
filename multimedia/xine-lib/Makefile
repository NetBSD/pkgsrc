# $NetBSD: Makefile,v 1.21 2005/05/02 11:29:35 drochner Exp $

.include "Makefile.common"

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=       	win32-codecs>=011227:../../multimedia/win32-codecs
PLIST_SUBST+=		I386=""
.else
PLIST_SUBST+=		I386="@comment "
.endif

BUILDLINK_DEPENDS.vcdimager+= vcdimager>=0.7.20nb1

SUBST_CLASSES+=		oss w32path

SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/audio_out/audio_oss_out.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_SED.oss+=		-e "s,\"dsp\",\"audio\",g"
.endif
SUBST_MESSAGE.oss=	"Fixing hardcoded audio device."

SUBST_STAGE.w32path=	post-patch
SUBST_FILES.w32path=	src/libw32dll/wine/module.c
SUBST_SED.w32path=	-e "s,@W32PATH@,${PREFIX}/lib/win32,"
SUBST_MESSAGE.w32path=	"Fixing win32 dll path."

# This needs to come before checking the values, otherwise the builtin.mk
# files are not doing its work.
.include "../../graphics/Mesa/buildlink3.mk"

USE_BUILTIN.MesaLib?=	no
USE_BUILTIN.glu?=	no

.if !empty(USE_BUILTIN.MesaLib:M[Yy][Ee][Ss]) && \
    !empty(USE_BUILTIN.glu:M[Yy][Ee][Ss])
PLIST_SUBST+=		OPENGL_PLUGIN=
.else
PLIST_SUBST+=		OPENGL_PLUGIN='@comment '
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../sysutils/vcdimager-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
