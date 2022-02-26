# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:58:20 pho Exp $

BUILDLINK_TREE+=	hs-network-info

.if !defined(HS_NETWORK_INFO_BUILDLINK3_MK)
HS_NETWORK_INFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-info+=	hs-network-info>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-network-info+=	hs-network-info>=0.2.1nb2
BUILDLINK_PKGSRCDIR.hs-network-info?=	../../net/hs-network-info
.endif	# HS_NETWORK_INFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-info
