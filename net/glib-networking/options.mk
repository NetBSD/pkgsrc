# $NetBSD: options.mk,v 1.1 2019/06/12 22:04:40 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glib-networking

PKG_OPTIONS_REQUIRED_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl

PKG_SUGGESTED_OPTIONS=		gnutls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gnutls openssl

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=	yes
BUILDLINK_API_DEPENDS.gnutls+= gnutls>=3.6.0nb1
.  include "../../security/gnutls/buildlink3.mk"
MESON_ARGS+=	-Dgnutls=enabled
MESON_ARGS+=	-Dopenssl=disabled
.elif !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=	yes
.  include "../../security/openssl/buildlink3.mk"
MESON_ARGS+=	-Dopenssl=enabled
MESON_ARGS+=	-Dgnutls=disabled
.endif
