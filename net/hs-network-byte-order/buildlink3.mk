# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:32:30 pho Exp $

BUILDLINK_TREE+=	hs-network-byte-order

.if !defined(HS_NETWORK_BYTE_ORDER_BUILDLINK3_MK)
HS_NETWORK_BYTE_ORDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-byte-order+=	hs-network-byte-order>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-network-byte-order+=	hs-network-byte-order>=0.1.7nb2
BUILDLINK_PKGSRCDIR.hs-network-byte-order?=	../../net/hs-network-byte-order
.endif	# HS_NETWORK_BYTE_ORDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-byte-order
