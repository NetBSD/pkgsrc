# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-inflect

.if !defined(GO_INFLECT_BUILDLINK3_MK)
GO_INFLECT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-inflect=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-inflect?=	build

BUILDLINK_API_DEPENDS.go-inflect+=	go-inflect>=0.0
BUILDLINK_PKGSRCDIR.go-inflect?=	../../textproc/go-inflect

.endif  # GO_INFLECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-inflect
