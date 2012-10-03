# $NetBSD: buildlink3.mk,v 1.3 2012/10/03 12:49:12 fhajny Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mysql-server>=5.5.11
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mysql55-server
BUILDLINK_LIBDIRS.mysql-server?=	lib

#.include "../../databases/mysql55-client/buildlink3.mk"
.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
