# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:36 wiz Exp $

BUILDLINK_TREE+=	libpreludedb-mysql

.if !defined(LIBPRELUDEDB_MYSQL_BUILDLINK3_MK)
LIBPRELUDEDB_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-mysql+=	libpreludedb-mysql>=0.9.15.3
BUILDLINK_ABI_DEPENDS.libpreludedb-mysql?=	libpreludedb-mysql>=0.9.15.3nb27
BUILDLINK_PKGSRCDIR.libpreludedb-mysql?=	../../security/libpreludedb-mysql

.endif	# LIBPRELUDEDB_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-mysql
