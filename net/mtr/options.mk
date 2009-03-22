# $NetBSD: options.mk,v 1.3 2009/03/22 16:21:44 smb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mtr
PKG_SUPPORTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif
