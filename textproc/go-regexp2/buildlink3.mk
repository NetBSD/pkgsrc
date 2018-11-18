# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:27:13 ryoon Exp $

BUILDLINK_TREE+=	go-regexp2

.if !defined(GO_REGEXP2_BUILDLINK3_MK)
GO_REGEXP2_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-regexp2=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-regexp2?=	build

BUILDLINK_API_DEPENDS.go-regexp2+=	go-regexp2>=1.1.6
BUILDLINK_PKGSRCDIR.go-regexp2?=	../../textproc/go-regexp2
.endif	# GO_REGEXP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-regexp2
