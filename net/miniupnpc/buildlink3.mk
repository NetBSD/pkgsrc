# $NetBSD: buildlink3.mk,v 1.1 2016/12/01 22:28:29 adam Exp $

BUILDLINK_TREE+=	miniupnpc

.if !defined(MINIUPNPC_BUILDLINK3_MK)
MINIUPNPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.miniupnpc+=	miniupnpc>=2.0
BUILDLINK_PKGSRCDIR.miniupnpc?=		../../net/miniupnpc
.endif	# MINIUPNPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-miniupnpc
