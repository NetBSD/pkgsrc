# $NetBSD: options.mk,v 1.2 2008/04/12 22:43:09 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_PREFIX.gtk2}
PLIST.x11=		yes
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wireshark
.endif
