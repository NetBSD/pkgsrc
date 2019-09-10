# $NetBSD: options.mk,v 1.1 2019/09/10 13:49:14 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.adplay
PKG_SUPPORTED_OPTIONS=		alsa sdl2
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} != "Linux" && ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		sdl2
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.else
CONFIGURE_ARGS+=	--disable-output-alsa
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--with-sdl=sdl2
.include "../../devel/SDL2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-output-sdl
.endif
