# $NetBSD: options.mk,v 1.1 2015/07/11 16:43:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgdata
PKG_SUPPORTED_OPTIONS=	gnome
#PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome
#.include "../../security/gnome-keyring/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif
