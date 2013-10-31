# $NetBSD: options.mk,v 1.4 2013/10/31 00:38:20 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mtr
PKG_SUPPORTED_OPTIONS=	gtk glib
PKG_SUGGESTED_OPTIONS=	glib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Mglib) || !empty(PKG_OPTIONS:Mgtk)
.include "../../devel/glib2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-glib
.endif
