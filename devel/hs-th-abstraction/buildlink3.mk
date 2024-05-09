# $NetBSD: buildlink3.mk,v 1.14 2024/05/09 01:32:15 pho Exp $

BUILDLINK_TREE+=	hs-th-abstraction

.if !defined(HS_TH_ABSTRACTION_BUILDLINK3_MK)
HS_TH_ABSTRACTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-abstraction+=	hs-th-abstraction>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-th-abstraction+=	hs-th-abstraction>=0.7.0.0nb1
BUILDLINK_PKGSRCDIR.hs-th-abstraction?=		../../devel/hs-th-abstraction
.endif	# HS_TH_ABSTRACTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-abstraction
