# $NetBSD: buildlink3.mk,v 1.2 2023/04/25 21:39:51 wiz Exp $

BUILDLINK_TREE+=	mbedtls3

.if !defined(MBEDTLS3_BUILDLINK3_MK)
MBEDTLS3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls3+=	mbedtls3>=3.4.0
BUILDLINK_PKGSRCDIR.mbedtls3?=		../../security/mbedtls3

pkgbase := mbedtls3
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.mbedtls3:Mzlib}
.include "../../devel/zlib/buildlink3.mk"
.endif
.endif	# MBEDTLS3_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls3
