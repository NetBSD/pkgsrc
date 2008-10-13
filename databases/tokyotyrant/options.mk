# $NetBSD: options.mk,v 1.1 2008/10/13 05:58:31 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tokyotyrant
PKG_SUPPORTED_OPTIONS=	lua
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--enable-lua
.include "../../lang/lua/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lua
.endif
