# $NetBSD: buildlink3.mk,v 1.1 2020/04/27 17:15:22 nikita Exp $

BUILDLINK_TREE+=	go-cmp

.if !defined(GO_CMP_BUILDLINK3_MK)
GO_CMP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cmp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cmp?=		build

BUILDLINK_API_DEPENDS.go-cmp+=		go-cmp>=0.4.0
BUILDLINK_PKGSRCDIR.go-cmp?=		../../devel/go-cmp

.endif	# GO_CMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cmp
