# $NetBSD: options.mk,v 1.7 2024/05/15 08:13:25 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnutls
PKG_SUPPORTED_OPTIONS=	dane pkcs11
PKG_SUGGESTED_OPTIONS=	pkcs11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdane)
.include "../../net/unbound/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdane
PLIST_SRC+=		PLIST.dane
.else
CONFIGURE_ARGS+=	--disable-libdane
.endif

PLIST_VARS+=	pkcs11
.if !empty(PKG_OPTIONS:Mpkcs11)
PLIST.pkcs11=	yes
BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.23.1
.include "../../security/p11-kit/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-p11-kit
.endif
