# $NetBSD: buildlink3.mk,v 1.16 2024/11/01 12:51:45 wiz Exp $

BUILDLINK_TREE+=	hs-direct-sqlite

.if !defined(HS_DIRECT_SQLITE_BUILDLINK3_MK)
HS_DIRECT_SQLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-direct-sqlite+=	hs-direct-sqlite>=2.3.29
BUILDLINK_ABI_DEPENDS.hs-direct-sqlite+=	hs-direct-sqlite>=2.3.29nb4
BUILDLINK_PKGSRCDIR.hs-direct-sqlite?=		../../databases/hs-direct-sqlite

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.45.3
.include "../../databases/sqlite3/buildlink3.mk"
.endif	# HS_DIRECT_SQLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-direct-sqlite
