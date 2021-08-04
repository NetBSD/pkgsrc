# $NetBSD: buildlink3.mk,v 1.1 2021/08/04 15:47:24 nia Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mariadb-server>=10.6.0<10.7.0
BUILDLINK_ABI_DEPENDS.mysql-server+=	mariadb-server>=10.6.0<10.7.0
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mariadb106-server
BUILDLINK_LIBDIRS.mysql-server+=	lib

.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
