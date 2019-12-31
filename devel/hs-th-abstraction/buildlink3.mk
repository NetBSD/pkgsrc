# $NetBSD: buildlink3.mk,v 1.1 2019/12/31 15:34:56 pho Exp $

BUILDLINK_TREE+=	hs-th-abstraction

.if !defined(HS_TH_ABSTRACTION_BUILDLINK3_MK)
HS_TH_ABSTRACTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-abstraction+=	hs-th-abstraction>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-th-abstraction+=	hs-th-abstraction>=0.3.1.0
BUILDLINK_PKGSRCDIR.hs-th-abstraction?=	../../devel/hs-th-abstraction
.endif	# HS_TH_ABSTRACTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-abstraction
