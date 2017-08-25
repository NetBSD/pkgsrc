# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-cast

.if !defined(GO_CAST_BUILDLINK3_MK)
GO_CAST_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cast=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cast?=		build

BUILDLINK_API_DEPENDS.go-cast+=		go-cast>=1.1.0
BUILDLINK_PKGSRCDIR.go-cast?=		../../devel/go-cast

.endif  # GO_CAST_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cast
