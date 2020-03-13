# $NetBSD: options.mk,v 1.21 2020/03/13 08:55:37 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lua

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	53	# needs lua_isyieldable, introduced in Lua 5.3
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--with-liblua=${BUILDLINK_PREFIX.lua}
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--without-liblua
.endif
