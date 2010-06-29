# $NetBSD: options.mk,v 1.5 2010/06/29 07:45:24 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=	gtk2 lua
PKG_SUGGESTED_OPTIONS=	gtk2 lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk2

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-wireshark
PLIST.gtk2=		yes
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wireshark
.endif

PLIST_VARS+=		lua

.if empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--with-lua=no
.else
.include "../../lang/lua/buildlink3.mk"

CONFIGURE_ARGS+=	--with-lua=${BUILDLINK_PREFIX.lua}
PLIST.lua=		yes
.endif
