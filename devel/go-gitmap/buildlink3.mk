# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:01 rillig Exp $

BUILDLINK_TREE+=	go-gitmap

.if !defined(GO_GITMAP_BUILDLINK3_MK)
GO_GITMAP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gitmap=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gitmap?=		build

BUILDLINK_API_DEPENDS.go-gitmap+=	go-gitmap>=0.0
BUILDLINK_PKGSRCDIR.go-gitmap?=		../../devel/go-gitmap

.endif  # GO_GITMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gitmap
