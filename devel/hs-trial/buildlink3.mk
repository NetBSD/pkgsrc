# $NetBSD: buildlink3.mk,v 1.4 2025/03/05 03:39:33 pho Exp $

BUILDLINK_TREE+=	hs-trial

.if !defined(HS_TRIAL_BUILDLINK3_MK)
HS_TRIAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-trial+=	hs-trial>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-trial+=	hs-trial>=0.0.0.0nb3
BUILDLINK_PKGSRCDIR.hs-trial?=		../../devel/hs-trial

.include "../../devel/hs-colourista/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.endif	# HS_TRIAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-trial
