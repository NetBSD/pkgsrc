# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:19 wiz Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mysql-server>=5.7.12
BUILDLINK_ABI_DEPENDS.mysql-server?=	mysql-server>=8.0.24nb7
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mysql57-server
BUILDLINK_LIBDIRS.mysql-server?=	lib

.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
