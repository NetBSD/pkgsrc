# $NetBSD: options.mk,v 1.1.1.1 2007/10/11 19:26:39 ghen Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ldapvi
PKG_SUPPORTED_OPTIONS=		sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
