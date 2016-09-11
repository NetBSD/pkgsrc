# $NetBSD: buildlink3.mk,v 1.1 2016/09/11 08:02:30 bsiegert Exp $

BUILDLINK_TREE+=	go-protobuf

.if !defined(GO_PROTOBUF_BUILDLINK3_MK)
GO_PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-protobuf=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-protobuf?=		build

BUILDLINK_API_DEPENDS.go-protobuf+=	go-protobuf>=20160829
BUILDLINK_PKGSRCDIR.go-protobuf?=	../../devel/go-protobuf
.endif	# GO_PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-protobuf
