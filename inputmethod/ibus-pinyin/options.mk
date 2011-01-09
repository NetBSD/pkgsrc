# $NetBSD: options.mk,v 1.2 2011/01/09 11:02:50 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ibus-pinyin
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
