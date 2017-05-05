# $NetBSD: buildlink3.mk,v 1.1 2017/05/05 00:05:40 mef Exp $

BUILDLINK_TREE+=	flxmlrpc

.if !defined(FLXMLRPC_BUILDLINK3_MK)
FLXMLRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flxmlrpc+=	flxmlrpc>=0.1.4
BUILDLINK_PKGSRCDIR.flxmlrpc?=	../../ham/flxmlrpc

.endif # FLXMLRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-flxmlrpc
