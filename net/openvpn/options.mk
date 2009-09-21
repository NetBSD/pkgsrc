# $NetBSD: options.mk,v 1.1 2009/09/21 12:33:31 spz Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.openvpn
PKG_SUPPORTED_OPTIONS=  pkcs11
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# include support for certificates on a stick (or card)

.if !empty(PKG_OPTIONS:Mpkcs11)
.include "../../security/pkcs11-helper/buildlink3.mk"
.else
# it would pick it up halfways when installed, and fail building
CONFIGURE_ARGS+= --disable-pkcs11
.endif
