# $NetBSD: buildlink3.mk,v 1.4 2019/11/04 21:43:36 rillig Exp $

BUILDLINK_TREE+=	go-text

.if !defined(GO_TEXT_BUILDLINK3_MK)
GO_TEXT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-text=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-text?=		build

BUILDLINK_API_DEPENDS.go-text+=	go-text>=0.3.0
BUILDLINK_PKGSRCDIR.go-text?=	../../textproc/go-text
.endif	# GO_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-text
