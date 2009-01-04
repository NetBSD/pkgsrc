# $NetBSD: options.mk,v 1.1.1.1 2009/01/04 01:05:46 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ctrlproxy

PKG_SUPPORTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Build in SSL support via gnutls
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/gnutls/buildlink3.mk"
.endif
