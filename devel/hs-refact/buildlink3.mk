# $NetBSD: buildlink3.mk,v 1.4 2022/02/26 03:58:05 pho Exp $

BUILDLINK_TREE+=	hs-refact

.if !defined(HS_REFACT_BUILDLINK3_MK)
HS_REFACT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-refact+=	hs-refact>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-refact+=	hs-refact>=0.3.0.2nb3
BUILDLINK_PKGSRCDIR.hs-refact?=		../../devel/hs-refact
.endif	# HS_REFACT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-refact
