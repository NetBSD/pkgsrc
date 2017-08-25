# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:15 jperkin Exp $

BUILDLINK_TREE+=	go-mmark

.if !defined(GO_MMARK_BUILDLINK3_MK)
GO_MMARK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mmark=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mmark?=		build

BUILDLINK_API_DEPENDS.go-mmark+=	go-mmark>=1.3.6
BUILDLINK_PKGSRCDIR.go-mmark?=		../../textproc/go-mmark

.include "../../www/go-toml-burntsushi/buildlink3.mk"
.endif  # GO_MMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mmark
