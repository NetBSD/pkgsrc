# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-buffruneio

.if !defined(GO_BUFFRUNEIO_BUILDLINK3_MK)
GO_BUFFRUNEIO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-buffruneio=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-buffruneio?=		build

BUILDLINK_API_DEPENDS.go-buffruneio+=		go-buffruneio>=0.2.0
BUILDLINK_PKGSRCDIR.go-buffruneio?=		../../devel/go-buffruneio

.endif  # GO_BUFFRUNEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-buffruneio
