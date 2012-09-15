# $NetBSD: buildlink3.mk,v 1.3 2012/09/15 15:03:22 obache Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mysql-server>=5.1.44<5.5
BUILDLINK_ABI_DEPENDS.mysql-server?=	mysql-server>=5.1.65<5.5
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mysql51-server
BUILDLINK_LIBDIRS.mysql-server?=	lib/mysql

.include "../../databases/mysql51-client/buildlink3.mk"
.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
