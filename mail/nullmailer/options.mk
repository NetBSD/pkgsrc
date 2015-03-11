# $NetBSD: options.mk,v 1.1 2015/03/11 15:18:51 wiedi Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.nullmailer
PKG_SUPPORTED_OPTIONS=  gnutls
PKG_SUGGESTED_OPTIONS=  gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tls
.endif # option gnutls

