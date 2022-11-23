# $NetBSD: buildlink3.mk,v 1.4 2022/11/23 16:18:34 adam Exp $

BUILDLINK_TREE+=	hs-direct-sqlite

.if !defined(HS_DIRECT_SQLITE_BUILDLINK3_MK)
HS_DIRECT_SQLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-direct-sqlite+=	hs-direct-sqlite>=2.3.26
BUILDLINK_ABI_DEPENDS.hs-direct-sqlite+=	hs-direct-sqlite>=2.3.26nb3
BUILDLINK_PKGSRCDIR.hs-direct-sqlite?=		../../databases/hs-direct-sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_DIRECT_SQLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-direct-sqlite
