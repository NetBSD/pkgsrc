# $NetBSD: buildlink3.mk,v 1.4 2016/12/04 05:17:04 ryoon Exp $

BUILDLINK_TREE+=	vsqlite++

.if !defined(VSQLITE++_BUILDLINK3_MK)
VSQLITE++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vsqlite+++=	vsqlite++>=0.3.13
BUILDLINK_ABI_DEPENDS.vsqlite++?=	vsqlite++>=0.3.13nb4
BUILDLINK_PKGSRCDIR.vsqlite++?=	../../databases/vsqlite++

.include "../../databases/sqlite3/buildlink3.mk"
.endif	# VSQLITE++_BUILDLINK3_MK

BUILDLINK_TREE+=	-vsqlite++
