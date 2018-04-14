# $NetBSD: options.mk,v 1.20 2018/04/14 13:04:33 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	inet6 lua
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lua

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	53	# needs lua_isyieldable, introduced in Lua 5.3
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--with-liblua=${BUILDLINK_PREFIX.lua}
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--without-liblua
.endif
