# $NetBSD: buildlink3.mk,v 1.1 2025/06/07 08:58:43 nia Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mariadb-server>=11.8.0<11.9.0
BUILDLINK_ABI_DEPENDS.mysql-server+=	mariadb-server>=11.8.0
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mariadb118-server
BUILDLINK_LIBDIRS.mysql-server+=	lib

.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
