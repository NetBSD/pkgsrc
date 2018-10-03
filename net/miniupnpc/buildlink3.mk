# $NetBSD: buildlink3.mk,v 1.2 2018/10/03 22:27:05 nia Exp $

BUILDLINK_TREE+=	miniupnpc

.if !defined(MINIUPNPC_BUILDLINK3_MK)
MINIUPNPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.miniupnpc+=	miniupnpc>=2.1
BUILDLINK_PKGSRCDIR.miniupnpc?=		../../net/miniupnpc
.endif	# MINIUPNPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-miniupnpc
