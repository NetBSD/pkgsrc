# $NetBSD: buildlink3.mk,v 1.3 2018/09/11 18:27:08 minskim Exp $

BUILDLINK_TREE+=	go-protobuf

.if !defined(GO_PROTOBUF_BUILDLINK3_MK)
GO_PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-protobuf=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-protobuf?=	build

BUILDLINK_API_DEPENDS.go-protobuf+=	go-protobuf>=1.2.0
BUILDLINK_PKGSRCDIR.go-protobuf?=	../../devel/go-protobuf
.endif	# GO_PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-protobuf
