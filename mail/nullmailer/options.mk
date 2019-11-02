# $NetBSD: options.mk,v 1.4 2019/11/02 16:25:24 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nullmailer
PKG_SUPPORTED_OPTIONS=	gnutls
PKG_SUGGESTED_OPTIONS=	gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tls
.else
CONFIGURE_ARGS+=	--disable-tls
.endif
