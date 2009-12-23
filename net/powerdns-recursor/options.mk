# $NetBSD: options.mk,v 1.1 2009/12/23 13:00:41 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.powerdns-recursor
PKG_SUPPORTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

###
### Build with Lua scripting support
###
.if !empty(PKG_OPTIONS:Mlua)
MAKE_ENV+=		LUA=1
MAKE_ENV+=		LUA_LIBS_CONFIG=-llua
.include "../../lang/lua/buildlink3.mk"
.endif

