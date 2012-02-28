# $NetBSD: options.mk,v 1.2 2012/02/28 10:49:27 roy Exp $

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
