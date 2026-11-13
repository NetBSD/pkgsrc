# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:11 pho Exp $

BUILDLINK_TREE+=	hs-prettyclass

.if !defined(HS_PRETTYCLASS_BUILDLINK3_MK)
HS_PRETTYCLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-prettyclass+=	hs-prettyclass>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-prettyclass+=	hs-prettyclass>=1.0.0.0nb2
BUILDLINK_PKGSRCDIR.hs-prettyclass?=	../../devel/hs-prettyclass

.endif	# HS_PRETTYCLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-prettyclass
