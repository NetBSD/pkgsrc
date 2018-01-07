# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:01 rillig Exp $

BUILDLINK_TREE+=	go-goptlib

.if !defined(GO_GOPTLIB_BUILDLINK3_MK)
GO_GOPTLIB_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goptlib=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goptlib?=	build

BUILDLINK_API_DEPENDS.go-goptlib+=	go-goptlib>=0.7
BUILDLINK_PKGSRCDIR.go-goptlib?=	../../devel/go-goptlib
.endif	# GO_GOPTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-goptlib
