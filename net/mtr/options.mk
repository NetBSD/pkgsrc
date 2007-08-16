# $NetBSD: options.mk,v 1.2 2007/08/16 23:12:21 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mtr
PKG_SUPPORTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif
