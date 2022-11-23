# $NetBSD: buildlink3.mk,v 1.18 2022/11/23 16:18:36 adam Exp $

BUILDLINK_TREE+=	vsqlite++

.if !defined(VSQLITE++_BUILDLINK3_MK)
VSQLITE++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vsqlite+++=	vsqlite++>=0.3.13
BUILDLINK_ABI_DEPENDS.vsqlite++?=	vsqlite++>=0.3.13nb18
BUILDLINK_PKGSRCDIR.vsqlite++?=		../../databases/vsqlite++

.include "../../databases/sqlite3/buildlink3.mk"
.endif	# VSQLITE++_BUILDLINK3_MK

BUILDLINK_TREE+=	-vsqlite++
