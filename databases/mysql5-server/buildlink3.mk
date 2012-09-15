# $NetBSD: buildlink3.mk,v 1.2 2012/09/15 13:00:03 obache Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mysql-server>=5.0<5.1
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mysql5-server
BUILDLINK_LIBDIRS.mysql-server?=	lib/mysql

.include "../../databases/mysql5-client/buildlink3.mk"
.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
