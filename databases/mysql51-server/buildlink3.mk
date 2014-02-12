# $NetBSD: buildlink3.mk,v 1.5 2014/02/12 23:17:39 tron Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mysql-server>=5.1.44<5.5
BUILDLINK_ABI_DEPENDS.mysql-server?=	mysql-server>=5.1.72nb1
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mysql51-server
BUILDLINK_LIBDIRS.mysql-server?=	lib/mysql

.include "../../databases/mysql51-client/buildlink3.mk"
.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
