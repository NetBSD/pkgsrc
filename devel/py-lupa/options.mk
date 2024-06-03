# $NetBSD: options.mk,v 1.5 2024/06/03 07:47:27 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-lupa
PKG_SUPPORTED_OPTIONS=	luajit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
.else
LUA_VERSIONS_ACCEPTED=	53 51 52
.include "../../lang/lua/buildlink3.mk"
.endif
