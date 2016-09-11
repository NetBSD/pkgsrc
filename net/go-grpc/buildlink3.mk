# $NetBSD: buildlink3.mk,v 1.1 2016/09/11 09:52:41 bsiegert Exp $

BUILDLINK_TREE+=	go-grpc

.if !defined(GO_GRPC_BUILDLINK3_MK)
GO_GRPC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-grpc=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-grpc?=		build

BUILDLINK_API_DEPENDS.go-grpc+=	go-grpc>=1.0.1
BUILDLINK_PKGSRCDIR.go-grpc?=	../../net/go-grpc

.include "../../devel/go-glog/buildlink3.mk"
.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-oauth2/buildlink3.mk"
.endif	# GO_GRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-grpc
