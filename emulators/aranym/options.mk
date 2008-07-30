# $NetBSD: options.mk,v 1.1 2008/07/30 14:08:59 hauke Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aranym
PKG_SUPPORTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--enable-opengl
.include "../../graphics/Mesa/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif
