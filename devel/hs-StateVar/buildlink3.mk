# $NetBSD: buildlink3.mk,v 1.1 2020/01/01 02:22:40 pho Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2
BUILDLINK_ABI_DEPENDS.hs-StateVar+=	hs-StateVar>=1.2
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../devel/hs-StateVar

.include "../../devel/hs-stm/buildlink3.mk"
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
