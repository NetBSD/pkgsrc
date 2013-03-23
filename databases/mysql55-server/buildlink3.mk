# $NetBSD: buildlink3.mk,v 1.5 2013/03/23 16:01:58 joerg Exp $

BUILDLINK_TREE+=	mysql-server

.if !defined(MYSQL_SERVER_BUILDLINK3_MK)
MYSQL_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-server+=	mysql-server>=5.5.11<5.6
BUILDLINK_ABI_DEPENDS.mysql-server?=	mysql-server>=5.5.29nb1<5.6
BUILDLINK_PKGSRCDIR.mysql-server?=	../../databases/mysql55-server
BUILDLINK_LIBDIRS.mysql-server?=	lib

#.include "../../databases/mysql55-client/buildlink3.mk"
.endif	# MYSQL_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-server
