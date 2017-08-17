# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:55:54 gavan Exp $

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

