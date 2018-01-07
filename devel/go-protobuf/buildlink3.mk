# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:02 rillig Exp $

BUILDLINK_TREE+=	go-protobuf

.if !defined(GO_PROTOBUF_BUILDLINK3_MK)
GO_PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-protobuf=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-protobuf?=	build

BUILDLINK_API_DEPENDS.go-protobuf+=	go-protobuf>=20160829
BUILDLINK_PKGSRCDIR.go-protobuf?=	../../devel/go-protobuf
.endif	# GO_PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-protobuf
