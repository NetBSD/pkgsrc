# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:22:23 ryoon Exp $

BUILDLINK_TREE+=	go-chroma

.if !defined(GO_CHROMA_BUILDLINK3_MK)
GO_CHROMA_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-chroma=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-chroma?=		build

BUILDLINK_API_DEPENDS.go-chroma+=	go-chroma>=0.5.0
BUILDLINK_PKGSRCDIR.go-chroma?=		../../textproc/go-chroma

.endif	# GO_CHROMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-chroma
