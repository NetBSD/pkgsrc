# $NetBSD: buildlink3.mk,v 1.2 2021/06/29 06:43:30 wiz Exp $

BUILDLINK_TREE+=	mysql-connector-c++

.if !defined(MYSQL_CONNECTOR_C++_BUILDLINK3_MK)
MYSQL_CONNECTOR_C++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-connector-c+++=	mysql-connector-c++>=8
BUILDLINK_PKGSRCDIR.mysql-connector-c++?=	../../databases/mysql-connector-c++

.include "../../mk/mysql.buildlink3.mk"
.endif	# MYSQL_CONNECTOR_C++_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-connector-c++
