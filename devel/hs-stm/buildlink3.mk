# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:08:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stm

.if !defined(HS_STM_BUILDLINK3_MK)
HS_STM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm+=	hs-stm>=2.4.3
BUILDLINK_ABI_DEPENDS.hs-stm+=	hs-stm>=2.4.3
BUILDLINK_PKGSRCDIR.hs-stm?=	../../devel/hs-stm
.endif	# HS_STM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm
