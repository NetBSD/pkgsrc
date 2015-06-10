# $NetBSD: options.mk,v 1.4 2015/06/10 14:22:29 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.powerdns-recursor
PKG_SUPPORTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

###
### Build with Lua scripting support
###
.if !empty(PKG_OPTIONS:Mlua)
MAKE_ENV+=		LUA=1
MAKE_ENV+=		LUA_LIBS_CONFIG=-llua
MAKE_ENV+=		LUA_CPPFLAGS_CONFIG=-I${PREFIX}/${LUA_INCDIR}
.include "../../lang/lua/buildlink3.mk"
.endif
