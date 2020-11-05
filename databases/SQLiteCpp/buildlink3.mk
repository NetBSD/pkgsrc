# $NetBSD: buildlink3.mk,v 1.8 2020/11/05 09:06:44 ryoon Exp $

BUILDLINK_TREE+=	SQLiteCpp

.if !defined(SQLITECPP_BUILDLINK3_MK)
SQLITECPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SQLiteCpp+=	SQLiteCpp>=2.2.0
BUILDLINK_DEPMETHOD.SQLiteCpp?=		build
BUILDLINK_ABI_DEPENDS.SQLiteCpp?=	SQLiteCpp>=2.2.0nb6
BUILDLINK_PKGSRCDIR.SQLiteCpp?=		../../databases/SQLiteCpp

.include "../../databases/sqlite3/buildlink3.mk"
.endif	# SQLITECPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-SQLiteCpp
