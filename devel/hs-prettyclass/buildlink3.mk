# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:06:53 pho Exp $

BUILDLINK_TREE+=	hs-prettyclass

.if !defined(HS_PRETTYCLASS_BUILDLINK3_MK)
HS_PRETTYCLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-prettyclass+=	hs-prettyclass>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-prettyclass+=	hs-prettyclass>=1.0.0.0nb1
BUILDLINK_PKGSRCDIR.hs-prettyclass?=	../../devel/hs-prettyclass

.endif	# HS_PRETTYCLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-prettyclass
