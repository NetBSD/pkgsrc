# $NetBSD: options.mk,v 1.1 2011/05/12 13:39:24 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcanberra
PKG_SUPPORTED_OPTIONS=	gtk
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk)
GCONF_SCHEMAS+=		libcanberra.schemas
PLIST.gtk=		yes
.include "../../x11/gtk2/buildlink3.mk"
.endif
