# $NetBSD: buildlink3.mk,v 1.23 2024/04/29 02:56:00 pho Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=3.2.0
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=3.2.0.0
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
