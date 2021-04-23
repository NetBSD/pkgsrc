# $NetBSD: buildlink3.mk,v 1.13 2021/04/23 10:03:01 pho Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=3.1.2
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=3.1.2.1
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
