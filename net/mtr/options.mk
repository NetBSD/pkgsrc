# $NetBSD: options.mk,v 1.1 2006/04/03 18:38:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mtr
PKG_SUPPORTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif
