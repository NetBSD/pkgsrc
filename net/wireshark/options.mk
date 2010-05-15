# $NetBSD: options.mk,v 1.4 2010/05/15 20:27:28 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=	gtk2 lua
PKG_SUGGESTED_OPTIONS=	gtk2 lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk2

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_PREFIX.gtk2}
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
