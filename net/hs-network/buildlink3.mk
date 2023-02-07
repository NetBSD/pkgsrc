# $NetBSD: buildlink3.mk,v 1.19 2023/02/07 01:41:02 pho Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=3.1.2
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=3.1.2.7nb3
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
