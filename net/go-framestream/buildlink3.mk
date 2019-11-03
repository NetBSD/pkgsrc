# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 11:45:35 rillig Exp $

BUILDLINK_TREE+=	go-framestream

.if !defined(GO_FRAMESTREAM_BUILDLINK3_MK)
GO_FRAMESTREAM_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-framestream=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-framestream?=		build

BUILDLINK_API_DEPENDS.go-framestream+=	go-framestream>=0.1.0
BUILDLINK_PKGSRCDIR.go-framestream?=	../../net/go-framestream

.endif	# GO_FRAMESTREAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-framestream
