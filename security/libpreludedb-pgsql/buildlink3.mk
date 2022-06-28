# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:37 wiz Exp $

BUILDLINK_TREE+=	libpreludedb-pgsql

.if !defined(LIBPRELUDEDB_PGSQL_BUILDLINK3_MK)
LIBPRELUDEDB_PGSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-pgsql+=	libpreludedb-pgsql>=0.9.15.3
BUILDLINK_ABI_DEPENDS.libpreludedb-pgsql?=	libpreludedb-pgsql>=0.9.15.3nb26
BUILDLINK_PKGSRCDIR.libpreludedb-pgsql?=	../../security/libpreludedb-pgsql

.endif	# LIBPRELUDEDB_PGSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-pgsql
