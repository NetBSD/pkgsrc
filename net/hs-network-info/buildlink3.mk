# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:20 pho Exp $

BUILDLINK_TREE+=	hs-network-info

.if !defined(HS_NETWORK_INFO_BUILDLINK3_MK)
HS_NETWORK_INFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-info+=	hs-network-info>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-network-info+=	hs-network-info>=0.2.0.10nb1
BUILDLINK_PKGSRCDIR.hs-network-info?=	../../net/hs-network-info
.endif	# HS_NETWORK_INFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-info
