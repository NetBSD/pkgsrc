# $NetBSD: buildlink3.mk,v 1.5 2016/03/05 11:27:42 jperkin Exp $

BUILDLINK_TREE+=	mongo-c-driver

.if !defined(MONGO_C_DRIVER_BUILDLINK3_MK)
MONGO_C_DRIVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mongo-c-driver+=	mongo-c-driver>=1.2.0
BUILDLINK_ABI_DEPENDS.mongo-c-driver?=	mongo-c-driver>=1.3.3nb1
BUILDLINK_PKGSRCDIR.mongo-c-driver?=	../../databases/mongo-c-driver

pkgbase := mongo-c-driver
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mongo-c-driver:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.mongo-c-driver:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/libbson/buildlink3.mk"
.endif	# MONGO_C_DRIVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mongo-c-driver
