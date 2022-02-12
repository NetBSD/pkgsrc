# $NetBSD: buildlink3.mk,v 1.7 2022/02/12 08:50:27 pho Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2
BUILDLINK_ABI_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.2nb1
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../devel/hs-StateVar
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
