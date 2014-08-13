# $NetBSD: buildlink3.mk,v 1.2 2014/08/13 10:57:32 adam Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.11.8
BUILDLINK_ABI_DEPENDS.botan?=	botan>=1.11.8nb2
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan-devel

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
