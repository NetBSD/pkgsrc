# $NetBSD: options.mk,v 1.1 2010/02/28 20:49:21 tonio Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup24
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS+= gnome

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
PKGCONFIG_OVERRIDE+=	libsoup-gnome-2.4.pc.in
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+= --without-gnome
.endif
