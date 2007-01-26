# $NetBSD: options.mk,v 1.1 2007/01/26 03:17:09 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdepim
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
PLIST_SUBST+=	HAVE_SASL=""
.else
PLIST_SUBST+=	HAVE_SASL="@comment "
.endif
