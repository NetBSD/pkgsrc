# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:39:47 pho Exp $

BUILDLINK_TREE+=	hs-network-multicast

.if !defined(HS_NETWORK_MULTICAST_BUILDLINK3_MK)
HS_NETWORK_MULTICAST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-multicast+=	hs-network-multicast>=0.3.2
BUILDLINK_ABI_DEPENDS.hs-network-multicast+=	hs-network-multicast>=0.3.2nb4
BUILDLINK_PKGSRCDIR.hs-network-multicast?=	../../net/hs-network-multicast

.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-bsd/buildlink3.mk"
.endif	# HS_NETWORK_MULTICAST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-multicast
