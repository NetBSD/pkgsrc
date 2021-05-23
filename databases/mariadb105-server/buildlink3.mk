# $NetBSD: buildlink3.mk,v 1.1 2021/05/23 15:32:48 nia Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mariadb-server>=10.5.0<10.6.0
BUILDLINK_ABI_DEPENDS.mysql-server+=	mariadb-server>=10.5.0<10.6.0
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mariadb105-server
BUILDLINK_LIBDIRS.mysql-server+=	lib

.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
