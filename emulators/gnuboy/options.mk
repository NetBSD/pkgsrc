# $NetBSD: options.mk,v 1.1 2023/07/21 09:32:36 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnuboy

PKG_OPTIONS_REQUIRED_GROUPS+=	sound
PKG_OPTIONS_GROUP.sound+=	libao oss

.include "../../mk/bsd.fast.prefs.mk"

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none" || ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=		libao
.else
PKG_SUGGESTED_OPTIONS+=		oss
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	--with-sound=oss
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	sys/oss/oss.c
SUBST_SED.oss=		-e 's,/dev/sound,${DEVOSSAUDIO},g'
SUBST_SED.oss+=		-e 's,/dev/dsp,${DEVOSSAUDIO},g'
.endif


.if !empty(PKG_OPTIONS:Mlibao)
CONFIGURE_ARGS+=	--with-sound=ao
.  include "../../audio/libao/buildlink3.mk"
.endif
