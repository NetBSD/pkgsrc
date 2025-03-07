# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 18:26:37 pho Exp $

BUILDLINK_TREE+=	hs-prettyclass

.if !defined(HS_PRETTYCLASS_BUILDLINK3_MK)
HS_PRETTYCLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-prettyclass+=	hs-prettyclass>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-prettyclass+=	hs-prettyclass>=1.0.0.0
BUILDLINK_PKGSRCDIR.hs-prettyclass?=	../../devel/hs-prettyclass

.endif	# HS_PRETTYCLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-prettyclass
