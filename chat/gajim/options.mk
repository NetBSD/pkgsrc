# $NetBSD: options.mk,v 1.2 2011/05/14 14:28:07 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gajim
PKG_SUPPORTED_OPTIONS=	avahi gnome gnome-keyring ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

# ssl
.if !empty(PKG_OPTIONS:Mssl)
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.9:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-amkCrypto-[0-9]*:../../security/py-amkCrypto
.endif

# avahi
.if !empty(PKG_OPTIONS:Mavahi)
DEPENDS+=	avahi-[0-9]*:../../net/avahi
.endif

# gnome
.if !empty(PKG_OPTIONS:Mgnome)
DEPENDS+=	${PYPKGPREFIX}-gnome2-[0-9]*:../../x11/py-gnome2
.endif

# gnome-keyring
.if !empty(PKG_OPTIONS:Mgnome-keyring)
DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop-[0-9]*:../../x11/py-gnome2-desktop
.endif
