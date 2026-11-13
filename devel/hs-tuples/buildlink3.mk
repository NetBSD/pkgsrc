# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:22 pho Exp $

BUILDLINK_TREE+=	hs-tuples

.if !defined(HS_TUPLES_BUILDLINK3_MK)
HS_TUPLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tuples+=	hs-tuples>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-tuples+=	hs-tuples>=0.1.0.0nb2
BUILDLINK_PKGSRCDIR.hs-tuples?=		../../devel/hs-tuples

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_TUPLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tuples
