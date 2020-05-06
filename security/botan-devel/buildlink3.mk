# $NetBSD: buildlink3.mk,v 1.19 2020/05/06 14:04:12 adam Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=2.11
BUILDLINK_ABI_DEPENDS.botan?=	botan>=2.11.0nb3
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan-devel

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
