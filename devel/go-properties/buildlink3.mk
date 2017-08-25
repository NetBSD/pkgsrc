# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:13 jperkin Exp $

BUILDLINK_TREE+=	go-properties

.if !defined(GO_PROPERTIES_BUILDLINK3_MK)
GO_PROPERTIES_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-properties=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-properties?=		build

BUILDLINK_API_DEPENDS.go-properties+=		go-properties>=1.7.0
BUILDLINK_PKGSRCDIR.go-properties?=		../../devel/go-properties

.endif  # GO_PROPERTIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-properties
