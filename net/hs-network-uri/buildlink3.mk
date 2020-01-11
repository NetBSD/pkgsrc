# $NetBSD: buildlink3.mk,v 1.2 2020/01/11 10:08:28 pho Exp $

BUILDLINK_TREE+=	hs-network-uri

.if !defined(HS_NETWORK_URI_BUILDLINK3_MK)
HS_NETWORK_URI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-uri+=	hs-network-uri>=2.6.1
BUILDLINK_ABI_DEPENDS.hs-network-uri+=	hs-network-uri>=2.6.1.0
BUILDLINK_PKGSRCDIR.hs-network-uri?=	../../net/hs-network-uri
.endif	# HS_NETWORK_URI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-uri
