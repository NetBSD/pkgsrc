# $NetBSD: buildlink3.mk,v 1.30 2024/05/16 06:15:31 wiz Exp $

BUILDLINK_TREE+=	pkcs11-helper

.if !defined(PKCS11_HELPER_BUILDLINK3_MK)
PKCS11_HELPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pkcs11-helper+=	pkcs11-helper>=1.06
BUILDLINK_ABI_DEPENDS.pkcs11-helper+=	pkcs11-helper>=1.30.0nb1
BUILDLINK_PKGSRCDIR.pkcs11-helper?=	../../security/pkcs11-helper

pkgbase := pkcs11-helper
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.pkcs11-helper:Mopenssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.pkcs11-helper:Mgnutls}
.  include "../../security/gnutls/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.pkcs11-helper:Mmbedtls}
.  include "../../security/mbedtls/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.pkcs11-helper:Mnss}
.  include "../../devel/nss/buildlink3.mk"
.endif

.endif # PKCS11_HELPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-pkcs11-helper
