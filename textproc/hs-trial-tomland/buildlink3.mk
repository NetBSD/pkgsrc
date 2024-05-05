# $NetBSD: buildlink3.mk,v 1.1 2024/05/05 08:34:19 pho Exp $

BUILDLINK_TREE+=	hs-trial-tomland

.if !defined(HS_TRIAL_TOMLAND_BUILDLINK3_MK)
HS_TRIAL_TOMLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-trial-tomland+=	hs-trial-tomland>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-trial-tomland+=	hs-trial-tomland>=0.0.0.0
BUILDLINK_PKGSRCDIR.hs-trial-tomland?=		../../textproc/hs-trial-tomland

.include "../../textproc/hs-tomland/buildlink3.mk"
.include "../../devel/hs-trial/buildlink3.mk"
.endif	# HS_TRIAL_TOMLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-trial-tomland
