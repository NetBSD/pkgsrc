# $NetBSD: buildlink3.mk,v 1.1 2018/06/13 16:19:31 minskim Exp $

BUILDLINK_TREE+=	go-resize

.if !defined(GO_RESIZE_BUILDLINK3_MK)
GO_RESIZE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-resize=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-resize?=		build

BUILDLINK_API_DEPENDS.go-resize+=	go-resize>=0.0.20180221
BUILDLINK_PKGSRCDIR.go-resize?=		../../graphics/go-resize
.endif	# GO_RESIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-resize
