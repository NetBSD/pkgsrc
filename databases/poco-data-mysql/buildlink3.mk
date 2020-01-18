# $NetBSD: buildlink3.mk,v 1.9 2020/01/18 21:48:00 jperkin Exp $

BUILDLINK_TREE+=	poco-data-mysql

.if !defined(POCO_DATA_MYSQL_BUILDLINK3_MK)
POCO_DATA_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-mysql+=	poco-data-mysql>=1.6.1
BUILDLINK_ABI_DEPENDS.poco-data-mysql+=	poco-data-mysql>=1.6.1nb2
BUILDLINK_PKGSRCDIR.poco-data-mysql?=	../../databases/poco-data-mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/poco-data/buildlink3.mk"
.endif # POCO_DATA_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-mysql
