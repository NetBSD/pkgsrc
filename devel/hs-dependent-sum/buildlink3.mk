# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:32 pho Exp $

BUILDLINK_TREE+=	hs-dependent-sum

.if !defined(HS_DEPENDENT_SUM_BUILDLINK3_MK)
HS_DEPENDENT_SUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dependent-sum+=	hs-dependent-sum>=0.7.2
BUILDLINK_ABI_DEPENDS.hs-dependent-sum+=	hs-dependent-sum>=0.7.2.0nb1
BUILDLINK_PKGSRCDIR.hs-dependent-sum?=		../../devel/hs-dependent-sum

.include "../../devel/hs-constraints-extras/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.endif	# HS_DEPENDENT_SUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dependent-sum
