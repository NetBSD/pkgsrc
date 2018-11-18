# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 07:46:43 ryoon Exp $

BUILDLINK_TREE+=	go-assert

.if !defined(GO_ASSERT_BUILDLINK3_MK)
GO_ASSERT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-assert=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-assert?=		build

BUILDLINK_API_DEPENDS.go-assert+=	go-assert>=0.0.0.20170929
BUILDLINK_PKGSRCDIR.go-assert?=		../../devel/go-assert

.endif	# GO_ASSERT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-assert
