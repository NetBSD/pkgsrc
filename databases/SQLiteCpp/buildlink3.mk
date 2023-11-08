# $NetBSD: buildlink3.mk,v 1.13 2023/11/08 13:18:22 wiz Exp $

BUILDLINK_TREE+=	SQLiteCpp

.if !defined(SQLITECPP_BUILDLINK3_MK)
SQLITECPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SQLiteCpp+=	SQLiteCpp>=2.2.0
BUILDLINK_DEPMETHOD.SQLiteCpp?=		build
BUILDLINK_ABI_DEPENDS.SQLiteCpp?=	SQLiteCpp>=2.2.0nb12
BUILDLINK_PKGSRCDIR.SQLiteCpp?=		../../databases/SQLiteCpp

.include "../../databases/sqlite3/buildlink3.mk"
.endif	# SQLITECPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-SQLiteCpp
