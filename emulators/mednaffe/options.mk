# $NetBSD: options.mk,v 1.1 2019/07/07 13:32:18 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mednaffe
PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk3 gtk2
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.endif
