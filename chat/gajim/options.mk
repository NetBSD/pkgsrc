# $NetBSD: options.mk,v 1.1.1.1 2010/12/24 00:02:29 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gajim
PKG_SUPPORTED_OPTIONS=	avahi gnome gnome-keyring ssl
PKG_SUGGESTED_OPTIONS=	avahi ssl

.include "../../mk/bsd.options.mk"

# ssl
.if !empty(PKG_OPTIONS:Mssl)
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
.include "../../security/py-amkCrypto/buildlink3.mk"
.endif

# avahi
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.endif

# gnome
.if !empty(PKG_OPTIONS:Mgnome)
.include "../../x11/py-gnome2/buildlink3.mk"
.endif

# avahi
.if !empty(PKG_OPTIONS:Mgnome-keyring)
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.endif
