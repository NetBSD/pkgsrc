# $NetBSD: options.mk,v 1.2 2017/10/28 04:51:06 schmonz Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.nullmailer
PKG_SUPPORTED_OPTIONS=  gnutls
PKG_SUGGESTED_OPTIONS=  gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tls
.else
CONFIGURE_ARGS+=	--disable-tls
.endif # option gnutls
