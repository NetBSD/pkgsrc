# $NetBSD: options.mk,v 1.2 2008/04/12 22:43:04 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdepim
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		sasl
.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
PLIST.sasl=		yes
.endif
