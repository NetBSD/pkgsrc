# $NetBSD: options.mk,v 1.2 2015/07/12 00:48:14 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgdata
PKG_SUPPORTED_OPTIONS=	gnome
#PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome
#.include "../../security/gnome-keyring/buildlink3.mk"
#.include "../../net/gnome-online-accounts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif
