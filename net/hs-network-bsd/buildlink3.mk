# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 04:54:42 pho Exp $

BUILDLINK_TREE+=	hs-network-bsd

.if !defined(HS_NETWORK_BSD_BUILDLINK3_MK)
HS_NETWORK_BSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-bsd+=	hs-network-bsd>=2.8.1
BUILDLINK_ABI_DEPENDS.hs-network-bsd+=	hs-network-bsd>=2.8.1.0nb3
BUILDLINK_PKGSRCDIR.hs-network-bsd?=	../../net/hs-network-bsd

.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_NETWORK_BSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-bsd
