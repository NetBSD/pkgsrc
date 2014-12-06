# $NetBSD: options.mk,v 1.2 2014/12/06 19:05:07 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aiksaurus
PKG_SUPPORTED_OPTIONS=	gtk
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk
.if !empty(PKG_OPTIONS:Mgtk)
PLIST.gtk=		yes
CONFIGURE_ARGS+=	--with-gtk
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif
