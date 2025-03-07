# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 16:25:36 pho Exp $

BUILDLINK_TREE+=	hs-tuples

.if !defined(HS_TUPLES_BUILDLINK3_MK)
HS_TUPLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tuples+=	hs-tuples>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-tuples+=	hs-tuples>=0.1.0.0
BUILDLINK_PKGSRCDIR.hs-tuples?=		../../devel/hs-tuples

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_TUPLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tuples
