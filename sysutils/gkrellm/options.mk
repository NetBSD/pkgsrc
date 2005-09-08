# $NetBSD: options.mk,v 1.1 2005/09/08 13:19:56 cube Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.${GKRELLM_PKGBASE}
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		gnutls ssl

PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
GKRELLM_SSL_TYPE=	openssl
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
GKRELLM_SSL_TYPE=	gnutls
.endif
