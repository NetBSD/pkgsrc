# $NetBSD: options.mk,v 1.2 2018/10/19 15:53:41 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.riemann-client
PKG_SUPPORTED_OPTIONS=	tls
PKG_SUGGESTED_OPTIONS+=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
CONFIGURE_ARGS+=	--enable-tls
.include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tls
.endif
