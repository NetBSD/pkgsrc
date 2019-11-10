# $NetBSD: buildlink3.mk,v 1.1 2019/11/10 14:42:43 ng0 Exp $

BUILDLINK_TREE+=	go-sqlite3

.if !defined(GO_SQLITE3_BUILDLINK3_MK)
GO_SQLITE3_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-sqlite3=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-sqlite3?=	build

BUILDLINK_API_DEPENDS.go-sqlite3+=	go-sqlite3>=1.10.0
BUILDLINK_PKGSRCDIR.go-sqlite3?=	../../databases/go-sqlite3
.endif	# GO_SQLITE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-sqlite3
