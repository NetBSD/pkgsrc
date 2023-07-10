# $NetBSD: buildlink3.mk,v 1.1 2023/07/10 22:55:50 nia Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mariadb-server>=10.11.0<10.12.0
BUILDLINK_ABI_DEPENDS.mysql-server+=	mariadb-server>=10.11.0
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mariadb1011-server
BUILDLINK_LIBDIRS.mysql-server+=	lib

.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
