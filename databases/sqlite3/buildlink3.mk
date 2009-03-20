# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:08 joerg Exp $

BUILDLINK_TREE+=	sqlite3

.if !defined(SQLITE3_BUILDLINK3_MK)
SQLITE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.0.8
BUILDLINK_ABI_DEPENDS.sqlite3+=	sqlite3>=3.2.7nb1
BUILDLINK_PKGSRCDIR.sqlite3?=	../../databases/sqlite3
.endif # SQLITE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlite3
