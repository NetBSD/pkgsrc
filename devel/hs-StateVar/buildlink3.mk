# $NetBSD: buildlink3.mk,v 1.10 2023/10/09 04:54:06 pho Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2
BUILDLINK_ABI_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2nb4
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../devel/hs-StateVar
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
