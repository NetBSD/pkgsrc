# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 07:57:34 ryoon Exp $

BUILDLINK_TREE+=	go-repr

.if !defined(GO_REPR_BUILDLINK3_MK)
GO_REPR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-repr=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-repr?=		build

BUILDLINK_API_DEPENDS.go-repr+=		go-repr>=0.0.0.20180921
BUILDLINK_PKGSRCDIR.go-repr?=		../../devel/go-repr
.endif	# GO_REPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-repr
