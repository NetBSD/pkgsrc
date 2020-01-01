# $NetBSD: buildlink3.mk,v 1.3 2020/01/01 02:18:07 pho Exp $

BUILDLINK_TREE+=	hs-stm

.if !defined(HS_STM_BUILDLINK3_MK)
HS_STM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm+=	hs-stm>=2.5.0
BUILDLINK_ABI_DEPENDS.hs-stm+=	hs-stm>=2.5.0.0
BUILDLINK_PKGSRCDIR.hs-stm?=	../../devel/hs-stm
.endif	# HS_STM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm
