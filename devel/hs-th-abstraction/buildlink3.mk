# $NetBSD: buildlink3.mk,v 1.7 2022/02/26 03:58:09 pho Exp $

BUILDLINK_TREE+=	hs-th-abstraction

.if !defined(HS_TH_ABSTRACTION_BUILDLINK3_MK)
HS_TH_ABSTRACTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-abstraction+=	hs-th-abstraction>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-th-abstraction+=	hs-th-abstraction>=0.4.3.0nb2
BUILDLINK_PKGSRCDIR.hs-th-abstraction?=		../../devel/hs-th-abstraction
.endif	# HS_TH_ABSTRACTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-abstraction
