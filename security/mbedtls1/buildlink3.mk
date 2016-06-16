# $NetBSD: buildlink3.mk,v 1.1 2016/06/16 09:21:11 fhajny Exp $

BUILDLINK_TREE+=	mbedtls

.if !defined(MBEDTLS_BUILDLINK3_MK)
MBEDTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls+=	mbedtls>=0.10.0<2
BUILDLINK_PKGSRCDIR.mbedtls?=	../../security/mbedtls1

pkgbase := mbedtls
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mbedtls:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif

.endif # MBEDTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls
