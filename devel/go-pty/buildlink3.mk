# $NetBSD: buildlink3.mk,v 1.2 2020/07/06 22:54:54 gutteridge Exp $

BUILDLINK_TREE+=	go-pty

.if !defined(GO_PTY_BUILDLINK3_MK)
GO_PTY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pty=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pty?=		build

BUILDLINK_API_DEPENDS.go-pty+=		go-pty>=1.1.11
BUILDLINK_PKGSRCDIR.go-pty?=		../../devel/go-pty

.include "../../devel/go-sys/buildlink3.mk"
.endif	# GO_PTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pty
