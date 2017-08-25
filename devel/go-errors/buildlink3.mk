# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-errors

.if !defined(GO_ERRORS_BUILDLINK3_MK)
GO_ERRORS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-errors=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-errors?=		build

BUILDLINK_API_DEPENDS.go-errors+=	go-errors>=0.6.0
BUILDLINK_PKGSRCDIR.go-errors?=		../../devel/go-errors

.endif  # GO_ERRORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-errors
