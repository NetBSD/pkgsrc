# $NetBSD: buildlink3.mk,v 1.16 2021/04/21 11:40:15 adam Exp $

BUILDLINK_TREE+=	vsqlite++

.if !defined(VSQLITE++_BUILDLINK3_MK)
VSQLITE++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vsqlite+++=	vsqlite++>=0.3.13
BUILDLINK_ABI_DEPENDS.vsqlite++?=	vsqlite++>=0.3.13nb15
BUILDLINK_PKGSRCDIR.vsqlite++?=		../../databases/vsqlite++

.include "../../databases/sqlite3/buildlink3.mk"
.endif	# VSQLITE++_BUILDLINK3_MK

BUILDLINK_TREE+=	-vsqlite++
