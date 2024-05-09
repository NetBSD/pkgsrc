# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:13 pho Exp $

BUILDLINK_TREE+=	hs-stm-chans

.if !defined(HS_STM_CHANS_BUILDLINK3_MK)
HS_STM_CHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm-chans+=	hs-stm-chans>=3.0.0
BUILDLINK_ABI_DEPENDS.hs-stm-chans+=	hs-stm-chans>=3.0.0.9nb2
BUILDLINK_PKGSRCDIR.hs-stm-chans?=	../../devel/hs-stm-chans
.endif	# HS_STM_CHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm-chans
