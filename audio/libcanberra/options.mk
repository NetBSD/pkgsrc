# $NetBSD: options.mk,v 1.4 2023/09/04 13:50:42 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcanberra
PKG_SUPPORTED_OPTIONS=	gtk gtk3
PKG_SUGGESTED_OPTIONS=	gtk3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk-any gtk gtk3

.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mgtk3)
PLIST.gtk-any=		yes
.endif

.if !empty(PKG_OPTIONS:Mgtk)
PLIST.gtk=		yes
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
PLIST.gtk3=		yes
.include "../../x11/gtk3/buildlink3.mk"
.endif
