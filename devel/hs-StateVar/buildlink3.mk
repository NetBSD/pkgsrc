# $NetBSD: buildlink3.mk,v 1.4 2021/05/03 19:00:54 pho Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.1
BUILDLINK_ABI_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2.1nb1
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../devel/hs-StateVar
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
