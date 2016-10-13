# $NetBSD: options.mk,v 1.1 2016/10/13 11:03:13 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.riemann-client
PKG_SUPPORTED_OPTIONS=	tls
PKG_SUGGESTED_OPTIONS+=	tls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		tls

.if !empty(PKG_OPTIONS:Mtls)
CONFIGURE_ARGS+=	--enable-tls
.include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tls
.endif
