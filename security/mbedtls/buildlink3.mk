# $NetBSD: buildlink3.mk,v 1.6 2023/08/14 05:25:10 wiz Exp $

BUILDLINK_TREE+=	mbedtls

.if !defined(MBEDTLS_BUILDLINK3_MK)
MBEDTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls+=	mbedtls>=0.10.0
BUILDLINK_ABI_DEPENDS.mbedtls?=	mbedtls>=2.28.3nb1
BUILDLINK_PKGSRCDIR.mbedtls?=	../../security/mbedtls

pkgbase := mbedtls
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.mbedtls:Mzlib}
.include "../../devel/zlib/buildlink3.mk"
.endif

.endif # MBEDTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls
