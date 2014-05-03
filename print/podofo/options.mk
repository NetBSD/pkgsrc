# $NetBSD: options.mk,v 1.2 2014/05/03 13:01:24 alnsn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.podofo
PKG_SUPPORTED_OPTIONS=		lua

.include "../../mk/bsd.options.mk"

###
### Lua support
###
.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_INCOMPATIBLE=	52
.  include "../../lang/lua/buildlink3.mk"
CMAKE_ARGS+=	-DLUA_ENABLED:LUA_ENABLED=true
.endif
