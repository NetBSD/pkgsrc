# $NetBSD: buildlink3.mk,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

BUILDLINK_TREE+=	mariadb-server

.if !defined(MARIADB_SERVER_BUILDLINK3_MK)
MARIADB_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-server+=	mariadb-server>=10.4.0
BUILDLINK_ABI_DEPENDS.mariadb-server+=	mariadb-server>=10.4.0
BUILDLINK_PKGSRCDIR.mariadb-server?=	../../databases/mariadb104-server
BUILDLINK_LIBDIRS.mariadb-server+=	lib

.endif	# MARIADB_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-server
