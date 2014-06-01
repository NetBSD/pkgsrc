# $NetBSD: options.mk,v 1.1 2014/06/01 13:30:35 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ibus-libpinyin
PKG_SUPPORTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lua

#
# Lua extension
#
.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lua-extension
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua-extension
.endif
