# $NetBSD: buildlink3.mk,v 1.1 2016/10/19 19:15:22 kamil Exp $

BUILDLINK_TREE+=	enet

.if !defined(ENET_BUILDLINK3_MK)
ENET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.enet+=	enet>=1.3.13
BUILDLINK_PKGSRCDIR.enet?=	../../net/enet
.endif	# ENET_BUILDLINK3_MK

BUILDLINK_TREE+=	-enet
