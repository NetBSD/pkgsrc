# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:18 wiz Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mariadb-server>=10.5.0<10.6.0
BUILDLINK_ABI_DEPENDS.mysql-server+=	mariadb-server>=10.5.16nb1
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mariadb105-server
BUILDLINK_LIBDIRS.mysql-server+=	lib

.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
