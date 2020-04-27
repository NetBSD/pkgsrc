# $NetBSD: buildlink3.mk,v 1.1 2020/04/27 16:31:22 nikita Exp $

BUILDLINK_TREE+=	go-levenshtein

.if !defined(GO_LEVENSHTEIN_BUILDLINK3_MK)
GO_LEVENSHTEIN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-levenshtein=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-levenshtein?=		build

BUILDLINK_API_DEPENDS.go-levenshtein+=		go-levenshtein>=1.2.3
BUILDLINK_PKGSRCDIR.go-levenshtein?=		../../devel/go-levenshtein

.endif	# GO_LEVENSHTEIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-levenshtein
