# $NetBSD: buildlink3.mk,v 1.1 2014/05/25 21:54:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stm

.if !defined(HS_STM_BUILDLINK3_MK)
HS_STM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm+=	hs-stm>=2.4.3
BUILDLINK_PKGSRCDIR.hs-stm?=	../../devel/hs-stm
.endif	# HS_STM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm
