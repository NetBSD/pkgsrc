# $NetBSD: buildlink3.mk,v 1.5 2022/08/11 06:40:38 wiz Exp $

BUILDLINK_TREE+=	mbedtls

.if !defined(MBEDTLS_BUILDLINK3_MK)
MBEDTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls+=	mbedtls>=0.10.0
BUILDLINK_ABI_DEPENDS.mbedtls?=	mbedtls>=2.28.1
BUILDLINK_PKGSRCDIR.mbedtls?=	../../security/mbedtls

pkgbase := mbedtls
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.mbedtls:Mzlib}
.include "../../devel/zlib/buildlink3.mk"
.endif

.endif # MBEDTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls
