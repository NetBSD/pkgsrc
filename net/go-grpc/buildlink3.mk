# $NetBSD: buildlink3.mk,v 1.2 2018/09/11 20:03:27 minskim Exp $

BUILDLINK_TREE+=	go-grpc

.if !defined(GO_GRPC_BUILDLINK3_MK)
GO_GRPC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-grpc=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-grpc?=		build

BUILDLINK_API_DEPENDS.go-grpc+=	go-grpc>=1.0.1
BUILDLINK_PKGSRCDIR.go-grpc?=	../../net/go-grpc

.include "../../devel/go-glog/buildlink3.mk"
.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../misc/go-genproto-googleapis-rpc/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-oauth2/buildlink3.mk"
.endif	# GO_GRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-grpc
