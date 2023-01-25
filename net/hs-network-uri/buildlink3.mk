# $NetBSD: buildlink3.mk,v 1.8 2023/01/25 04:21:42 pho Exp $

BUILDLINK_TREE+=	hs-network-uri

.if !defined(HS_NETWORK_URI_BUILDLINK3_MK)
HS_NETWORK_URI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-uri+=	hs-network-uri>=2.6.4
BUILDLINK_ABI_DEPENDS.hs-network-uri+=	hs-network-uri>=2.6.4.2
BUILDLINK_PKGSRCDIR.hs-network-uri?=	../../net/hs-network-uri

.include "../../devel/hs-th-compat/buildlink3.mk"
.endif	# HS_NETWORK_URI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-uri
