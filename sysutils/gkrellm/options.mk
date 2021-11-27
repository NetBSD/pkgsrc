# $NetBSD: options.mk,v 1.2 2021/11/27 05:37:59 pho Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gkrellm
PKG_OPTIONS_OPTIONAL_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		gnutls openssl

PKG_OPTIONS_LEGACY_OPTS+=	ssl:openssl
PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
GKRELLM_SSL_TYPE=	openssl
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
GKRELLM_SSL_TYPE=	gnutls
.endif
