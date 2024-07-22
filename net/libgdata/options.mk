# $NetBSD: options.mk,v 1.3 2024/07/22 20:46:14 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgdata
PKG_SUPPORTED_OPTIONS=	gnome
#PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
MESON_ARGS+=	-Dgnome=enabled
#.include "../../security/gnome-keyring/buildlink3.mk"
#.include "../../net/gnome-online-accounts/buildlink3.mk"
.else
MESON_ARGS+=	-Dgnome=disabled
.endif
