# $NetBSD: buildlink3.mk,v 1.1 2025/06/15 13:30:19 ryoon Exp $

BUILDLINK_TREE+=	duckdb

.if !defined(DUCKDB_BUILDLINK3_MK)
DUCKDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.duckdb+=	duckdb>=1.2.2
BUILDLINK_PKGSRCDIR.duckdb?=	../../databases/duckdb

.endif	# DUCKDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-duckdb
