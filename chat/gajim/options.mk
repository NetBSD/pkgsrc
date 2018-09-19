# $NetBSD: options.mk,v 1.11 2018/09/19 16:18:32 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gajim
PKG_SUPPORTED_OPTIONS=	avahi dbus
PKG_SUGGESTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

# avahi
.if !empty(PKG_OPTIONS:Mavahi)
DEPENDS+=	avahi-[0-9]*:../../net/avahi
.endif

# dbus
.if !empty(PKG_OPTIONS:Mdbus)
DEPENDS+=	${PYPKGPREFIX}-dbus>=0.81:../../sysutils/py-dbus
.endif
