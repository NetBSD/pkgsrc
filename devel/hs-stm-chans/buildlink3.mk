# $NetBSD: buildlink3.mk,v 1.10 2025/08/13 11:06:59 pho Exp $

BUILDLINK_TREE+=	hs-stm-chans

.if !defined(HS_STM_CHANS_BUILDLINK3_MK)
HS_STM_CHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm-chans+=	hs-stm-chans>=3.0.0
BUILDLINK_ABI_DEPENDS.hs-stm-chans+=	hs-stm-chans>=3.0.0.9nb5
BUILDLINK_PKGSRCDIR.hs-stm-chans?=	../../devel/hs-stm-chans
.endif	# HS_STM_CHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm-chans
