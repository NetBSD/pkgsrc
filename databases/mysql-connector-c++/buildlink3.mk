# $NetBSD: buildlink3.mk,v 1.1 2015/03/19 01:06:25 rodent Exp $

BUILDLINK_TREE+=	mysql-connector-c++

.if !defined(MYSQL_CONNECTOR_C++_BUILDLINK3_MK)
MYSQL_CONNECTOR_C++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-connector-c+++=	mysql-connector-c++>=1.1.5
BUILDLINK_PKGSRCDIR.mysql-connector-c++?=	../../databases/mysql-connector-c++

.include "../../mk/mysql.buildlink3.mk"
.endif	# MYSQL_CONNECTOR_C++_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-connector-c++
