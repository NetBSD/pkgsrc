# $NetBSD: buildlink3.mk,v 1.22 2023/11/02 06:37:17 pho Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=3.1.4
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=3.1.4.0nb1
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
