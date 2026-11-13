# $NetBSD: buildlink3.mk,v 1.16 2026/11/13 14:38:46 pho Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2
BUILDLINK_ABI_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2nb10
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../devel/hs-StateVar
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
