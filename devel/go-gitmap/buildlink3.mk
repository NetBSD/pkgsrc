# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:26:34 gavan Exp $

BUILDLINK_TREE+=	go-gitmap

.if !defined(GO_GITMAP_BUILDLINK3_MK)
GO_GITMAP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gitmap=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gitmap?=		build

BUILDLINK_API_DEPENDS.go-gitmap+=		go-gitmap>=0.0
BUILDLINK_PKGSRCDIR.go-gitmap?=		../../devel/go-gitmap

.endif  # GO_GITMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gitmap

