# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-amber

.if !defined(GO_AMBER_BUILDLINK3_MK)
GO_AMBER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-amber=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-amber?=		build

BUILDLINK_API_DEPENDS.go-amber+=	go-amber>=0.0
BUILDLINK_PKGSRCDIR.go-amber?=		../../devel/go-amber

.endif  # GO_AMBER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-amber
