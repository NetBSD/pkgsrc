# $NetBSD: buildlink3.mk,v 1.28 2025/08/13 11:07:18 pho Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=3.2.7
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=3.2.7.0nb3
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
