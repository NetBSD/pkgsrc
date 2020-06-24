# $NetBSD: buildlink3.mk,v 1.1 2020/06/24 20:29:25 nikita Exp $

BUILDLINK_TREE+=	go-goldmark

.if !defined(GO_GOLDMARK_BUILDLINK3_MK)
GO_GOLDMARK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goldmark=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goldmark?=	build

BUILDLINK_API_DEPENDS.go-goldmark+=	go-goldmark>=1.1.30
BUILDLINK_PKGSRCDIR.go-goldmark?=	../../textproc/go-goldmark

.endif	# GO_GOLDMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-goldmark
