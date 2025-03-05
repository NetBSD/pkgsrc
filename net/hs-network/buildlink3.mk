# $NetBSD: buildlink3.mk,v 1.27 2025/03/05 03:39:46 pho Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=3.2.7
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=3.2.7.0nb2
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
