# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:15:39 gavan Exp $

BUILDLINK_TREE+=	go-amber

.if !defined(GO_AMBER_BUILDLINK3_MK)
GO_AMBER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-amber=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-amber?=		build

BUILDLINK_API_DEPENDS.go-amber+=	go-amber>=0.0
BUILDLINK_PKGSRCDIR.go-amber?=		../../devel/go-amber

.endif  # GO_AMBER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-amber

