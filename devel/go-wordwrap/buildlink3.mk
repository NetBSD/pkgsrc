# $NetBSD: buildlink3.mk,v 1.1 2020/04/27 15:15:08 nikita Exp $

BUILDLINK_TREE+=	go-wordwrap

.if !defined(GO_WORDWRAP_BUILDLINK3_MK)
GO_WORDWRAP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-wordwrap=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-wordwrap?=	build

BUILDLINK_API_DEPENDS.go-wordwrap+=	go-wordwrap>=1.0.0
BUILDLINK_PKGSRCDIR.go-wordwrap?=	../../devel/go-wordwrap

.endif	# GO_WORDWRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-wordwrap
