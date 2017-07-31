# $NetBSD: options.mk,v 1.1 2017/07/31 20:40:19 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mailfront
PKG_SUPPORTED_OPTIONS+=	lua
PKG_SUGGESTED_OPTIONS+=	lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		lua
.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	51
.  include "../../lang/lua/buildlink3.mk"
BUILD_TARGET+=		lua
PLIST.lua=		yes
.endif
