# $NetBSD: buildlink3.mk,v 1.1 2025/09/28 16:25:06 bsiegert Exp $

BUILDLINK_TREE+=	rpcsvc-proto

.if !defined(RPCSVC_PROTO_BUILDLINK3_MK)
RPCSVC_PROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.rpcsvc-proto?=	build

BUILDLINK_API_DEPENDS.rpcsvc-proto+=	rpcsvc-proto>=1.4.4
BUILDLINK_PKGSRCDIR.rpcsvc-proto?=	../../devel/rpcsvc-proto

TOOLS_PATH.rpcgen=		${PREFIX}/bin/rpcgen

.endif	# RPCSVC_PROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-rpcsvc-proto
