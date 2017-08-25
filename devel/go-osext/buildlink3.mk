# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:13 jperkin Exp $

BUILDLINK_TREE+=	go-osext

.if !defined(GO_OSEXT_BUILDLINK3_MK)
GO_OSEXT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-osext=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-osext?=		build

BUILDLINK_API_DEPENDS.go-osext+=	go-osext>=0.0
BUILDLINK_PKGSRCDIR.go-osext?=		../../devel/go-osext

.endif  # GO_OSEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-osext
