# $NetBSD: options.mk,v 1.3 2020/01/20 21:31:02 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mp3blaster
PKG_SUPPORTED_OPTIONS=	sdl

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS=	sdl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl=yes
.include "../../devel/SDL/buildlink3.mk"
.endif
