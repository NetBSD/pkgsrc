# $NetBSD: options.mk,v 1.2 2010/06/14 17:58:44 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup24
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS+= gnome

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
PKGCONFIG_OVERRIDE+=	libsoup-gnome-2.4.pc.in
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+= --without-gnome
.endif
