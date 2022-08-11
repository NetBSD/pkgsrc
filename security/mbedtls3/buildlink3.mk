# $NetBSD: buildlink3.mk,v 1.1 2022/08/11 06:49:16 wiz Exp $

BUILDLINK_TREE+=	mbedtls3

.if !defined(MBEDTLS3_BUILDLINK3_MK)
MBEDTLS3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls3+=	mbedtls3>=3.2.1
BUILDLINK_PKGSRCDIR.mbedtls3?=		../../security/mbedtls3

pkgbase := mbedtls3
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.mbedtls3:Mzlib}
.include "../../devel/zlib/buildlink3.mk"
.endif
.endif	# MBEDTLS3_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls3
