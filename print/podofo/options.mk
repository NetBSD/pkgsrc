# $NetBSD: options.mk,v 1.3 2024/08/25 06:19:10 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.podofo
PKG_SUPPORTED_OPTIONS=		lua

.include "../../mk/bsd.options.mk"

###
### Lua support
###
.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_INCOMPATIBLE=	52
.  include "../../lang/lua/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DLUA_ENABLED:LUA_ENABLED=true
.endif
