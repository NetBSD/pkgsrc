# $NetBSD: options.mk,v 1.1 2026/11/14 07:32:58 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.stirmake
PKG_SUPPORTED_OPTIONS=

PKG_OPTIONS_OPTIONAL_GROUPS=	luaconf
PKG_OPTIONS_GROUP.luaconf=	lua luajit

PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

STIR_WITH_LUA=		0
STIR_LUAINCS=
STIR_LUALIBS=

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	55 54 53 52 51
.include "../../lang/lua/buildlink3.mk"
STIR_WITH_LUA=		1
STIR_LUAINCS=		-I.
STIR_LUALIBS=		-llua
.elif !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
STIR_WITH_LUA=		1
STIR_LUAINCS=		-I.
STIR_LUALIBS=		-lluajit-5.1
.endif
