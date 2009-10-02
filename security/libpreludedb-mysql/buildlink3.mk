# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 10:02:08 hasso Exp $

BUILDLINK_TREE+=	libpreludedb-mysql

.if !defined(LIBPRELUDEDB_MYSQL_BUILDLINK3_MK)
LIBPRELUDEDB_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-mysql+=	libpreludedb-mysql>=0.9.15.3
BUILDLINK_PKGSRCDIR.libpreludedb-mysql?=	../../security/libpreludedb-mysql

.endif	# LIBPRELUDEDB_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-mysql
