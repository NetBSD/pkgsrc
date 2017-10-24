# $NetBSD: buildlink3.mk,v 1.1 2017/10/24 06:53:26 maya Exp $

BUILDLINK_TREE+=	go-shellwords

.if !defined(GO_SHELLWORDS_BUILDLINK3_MK)
GO_SHELLWORDS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-shellwords=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-shellwords?=		build

BUILDLINK_API_DEPENDS.go-shellwords+=		go-shellwords>=0.0
BUILDLINK_PKGSRCDIR.go-shellwords?=		../../devel/go-shellwords

.endif  # GO_SHELLWORDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-shellwords
