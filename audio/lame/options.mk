# $NetBSD: options.mk,v 1.1 2005/05/31 16:04:28 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lame
PKG_SUPPORTED_OPTIONS=	gtk
PKG_OPTIONS_LEGACY_VARS+= LAME_USE_GTK:gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ENV+=		GTK_CONFIG=${BUILDLINK_PREFIX.gtk}/bin/gtk-config
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-analyzer
.endif
