# $NetBSD: buildlink3.mk,v 1.1 2020/06/29 12:46:01 nikita Exp $

BUILDLINK_TREE+=	go-pty

.if !defined(GO_PTY_BUILDLINK3_MK)
GO_PTY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pty=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pty?=		build

BUILDLINK_API_DEPENDS.go-pty+=		go-pty>=1.1.11
BUILDLINK_PKGSRCDIR.go-pty?=		../../devel/go-pty

.endif	# GO_PTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pty
