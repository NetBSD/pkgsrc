# $NetBSD: buildlink3.mk,v 1.11 2023/11/02 06:36:17 pho Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2
BUILDLINK_ABI_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2nb5
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../devel/hs-StateVar
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
