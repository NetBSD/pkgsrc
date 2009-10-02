# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 10:03:08 hasso Exp $

BUILDLINK_TREE+=	libpreludedb-pgsql

.if !defined(LIBPRELUDEDB_PGSQL_BUILDLINK3_MK)
LIBPRELUDEDB_PGSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-pgsql+=	libpreludedb-pgsql>=0.9.15.3
BUILDLINK_PKGSRCDIR.libpreludedb-pgsql?=	../../security/libpreludedb-pgsql

.endif	# LIBPRELUDEDB_PGSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-pgsql
