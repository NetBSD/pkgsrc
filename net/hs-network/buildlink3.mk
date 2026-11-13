# $NetBSD: buildlink3.mk,v 1.29 2026/11/13 14:39:38 pho Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=3.2.7
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=3.2.7.0nb4
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
