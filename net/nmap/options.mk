# $NetBSD: options.mk,v 1.22 2021/03/19 08:50:57 sborrill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	lua liblinear

PKG_SUGGESTED_OPTIONS=	liblinear

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

.if !empty(PKG_OPTIONS:Mliblinear)
# liblinear is used for IPv6 OS detection machine learning techniques
.include "../../math/liblinear/buildlink3.mk"
CONFIGURE_ARGS+=	--with-liblinear=${BUILDLINK_PREFIX.liblinear}
.else
CONFIGURE_ARGS+=	--without-liblinear
.endif
