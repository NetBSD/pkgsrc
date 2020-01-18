# $NetBSD: buildlink3.mk,v 1.9 2020/01/18 21:47:59 jperkin Exp $

BUILDLINK_TREE+=	mongo-c-driver

.if !defined(MONGO_C_DRIVER_BUILDLINK3_MK)
MONGO_C_DRIVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mongo-c-driver+=	mongo-c-driver>=1.14.0
BUILDLINK_ABI_DEPENDS.mongo-c-driver+=	mongo-c-driver>=1.14.0nb2
BUILDLINK_PKGSRCDIR.mongo-c-driver?=	../../databases/mongo-c-driver

pkgbase := mongo-c-driver
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mongo-c-driver:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.mongo-c-driver:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# MONGO_C_DRIVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mongo-c-driver
