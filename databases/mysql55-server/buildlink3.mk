# $NetBSD: buildlink3.mk,v 1.2 2011/04/27 08:49:01 adam Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mysql-server>=5.5.11
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mysql55-server

#.include "../../databases/mysql55-client/buildlink3.mk"
.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
