# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:05 joerg Exp $

BUILDLINK_TREE+=	dbh

.if !defined(DBH_BUILDLINK3_MK)
DBH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbh+=		dbh>=1.0.22
BUILDLINK_PKGSRCDIR.dbh?=	../../databases/dbh
.endif # DBH_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbh
