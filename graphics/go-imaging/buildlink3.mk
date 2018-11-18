# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:32:54 ryoon Exp $

BUILDLINK_TREE+=	go-imaging

.if !defined(GO_IMAGING_BUILDLINK3_MK)
GO_IMAGING_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-imaging=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-imaging?=	build

BUILDLINK_API_DEPENDS.go-imaging+=	go-imaging>=1.5.0
BUILDLINK_PKGSRCDIR.go-imaging?=	../../graphics/go-imaging

.endif	# GO_IMAGING_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-imaging
