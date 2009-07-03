# $NetBSD: options.mk,v 1.6 2009/07/03 14:23:00 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.weechat
PKG_SUPPORTED_OPTIONS=	charset gnutls python lua wide-curses
PKG_SUGGESTED_OPTIONS=	charset

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		charset lua plugin python

.if !empty(PKG_OPTIONS:Mcharset)
CONFIGURE_ARGS+=	--enable-charset
PLIST.charset=		yes
.else
CONFIGURE_ARGS+=	--disable-charset
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
.include "../../devel/ncursesw/buildlink3.mk"
.else
.include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
CONFIGURE_ARGS+=	--enable-python
PLIST.python=		yes
.else
CONFIGURE_ARGS+=	--disable-python
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lua
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mpython) || \
    !empty(PKG_OPTIONS:Mlua) || \
    !empty(PKG_OPTIONS:Mcharset)
PLIST.plugin=		yes
.endif
