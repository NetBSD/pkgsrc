# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:36:57 pho Exp $

BUILDLINK_TREE+=	hs-storable-tuple

.if !defined(HS_STORABLE_TUPLE_BUILDLINK3_MK)
HS_STORABLE_TUPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-storable-tuple+=	hs-storable-tuple>=0.1
BUILDLINK_ABI_DEPENDS.hs-storable-tuple+=	hs-storable-tuple>=0.1nb1
BUILDLINK_PKGSRCDIR.hs-storable-tuple?=		../../devel/hs-storable-tuple

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-storable-record/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.endif	# HS_STORABLE_TUPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-storable-tuple
