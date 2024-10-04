# $NetBSD: buildlink3.mk,v 1.9 2024/10/04 03:49:34 ryoon Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=2.11
BUILDLINK_ABI_DEPENDS.botan+=	botan>=2.19.4nb1
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan2

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
