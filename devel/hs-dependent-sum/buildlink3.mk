# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:31:52 pho Exp $

BUILDLINK_TREE+=	hs-dependent-sum

.if !defined(HS_DEPENDENT_SUM_BUILDLINK3_MK)
HS_DEPENDENT_SUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dependent-sum+=	hs-dependent-sum>=0.7.2
BUILDLINK_ABI_DEPENDS.hs-dependent-sum+=	hs-dependent-sum>=0.7.2.0nb4
BUILDLINK_PKGSRCDIR.hs-dependent-sum?=		../../devel/hs-dependent-sum

.include "../../devel/hs-constraints-extras/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.endif	# HS_DEPENDENT_SUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dependent-sum
