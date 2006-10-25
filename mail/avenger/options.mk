# $NetBSD: options.mk,v 1.1.1.1 2006/10/25 14:05:31 rillig Exp $
#

PKG_SUPPORTED_OPTIONS=		sasl
PKG_SUGGESTED_OPTIONS=		# none
PKG_OPTIONS_VAR=		PKG_OPTIONS.avenger

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-sasl
.else
CONFIGURE_ARGS+=		--disable-sasl
.endif
