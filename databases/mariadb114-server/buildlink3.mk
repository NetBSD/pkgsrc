# $NetBSD: buildlink3.mk,v 1.1 2024/08/21 21:08:35 nia Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mariadb-server>=11.4.0<11.5.0
BUILDLINK_ABI_DEPENDS.mysql-server+=	mariadb-server>=11.4.0
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mariadb114-server
BUILDLINK_LIBDIRS.mysql-server+=	lib

.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
