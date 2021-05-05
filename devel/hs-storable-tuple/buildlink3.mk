# $NetBSD: buildlink3.mk,v 1.1 2021/05/05 11:58:24 pho Exp $

BUILDLINK_TREE+=	hs-storable-tuple

.if !defined(HS_STORABLE_TUPLE_BUILDLINK3_MK)
HS_STORABLE_TUPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-storable-tuple+=	hs-storable-tuple>=0.0.3
BUILDLINK_ABI_DEPENDS.hs-storable-tuple+=	hs-storable-tuple>=0.0.3.3
BUILDLINK_PKGSRCDIR.hs-storable-tuple?=		../../devel/hs-storable-tuple

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-storable-record/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.endif	# HS_STORABLE_TUPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-storable-tuple
