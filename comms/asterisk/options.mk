# $NetBSD: options.mk,v 1.4 2011/10/06 08:35:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
MAKE_FLAGS+=		ASTERISK_USE_GTK=1
PLIST.gtk=		yes
.endif
