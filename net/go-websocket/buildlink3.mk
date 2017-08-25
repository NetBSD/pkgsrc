# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-websocket

.if !defined(GO_WEBSOCKET_BUILDLINK3_MK)
GO_WEBSOCKET_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-websocket=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-websocket?=	build

BUILDLINK_API_DEPENDS.go-websocket+=	go-websocket>=1.0.0
BUILDLINK_PKGSRCDIR.go-websocket?=	../../net/go-websocket

.endif  # GO_WEBSOCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-websocket
