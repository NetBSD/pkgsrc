# $NetBSD: buildlink3.mk,v 1.1 2018/09/11 19:57:37 minskim Exp $

BUILDLINK_TREE+=	go-genproto-googleapis-rpc

.if !defined(GO_GENPROTO_GOOGLEAPIS_RPC_BUILDLINK3_MK)
GO_GENPROTO_GOOGLEAPIS_RPC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-genproto-googleapis-rpc=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-genproto-googleapis-rpc?=	build

BUILDLINK_API_DEPENDS.go-genproto-googleapis-rpc+=	go-genproto-googleapis-rpc>=20180901
BUILDLINK_PKGSRCDIR.go-genproto-googleapis-rpc?=	../../misc/go-genproto-googleapis-rpc

.include "../../devel/go-protobuf/buildlink3.mk"
.endif	# GO_GENPROTO_GOOGLEAPIS_RPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-genproto-googleapis-rpc
