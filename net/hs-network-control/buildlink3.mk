# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:30 pho Exp $

BUILDLINK_TREE+=	hs-network-control

.if !defined(HS_NETWORK_CONTROL_BUILDLINK3_MK)
HS_NETWORK_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-control+=	hs-network-control>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-network-control+=	hs-network-control>=0.1.0nb1
BUILDLINK_PKGSRCDIR.hs-network-control?=	../../net/hs-network-control

.include "../../devel/hs-psqueues/buildlink3.mk"
.include "../../time/hs-unix-time/buildlink3.mk"
.endif	# HS_NETWORK_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-control
