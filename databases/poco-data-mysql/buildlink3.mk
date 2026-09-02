# $NetBSD: buildlink3.mk,v 1.12 2026/09/02 19:01:18 wiz Exp $

BUILDLINK_TREE+=	poco-data-mysql

.if !defined(POCO_DATA_MYSQL_BUILDLINK3_MK)
POCO_DATA_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-mysql+=	poco-data-mysql>=1.6.1
BUILDLINK_ABI_DEPENDS.poco-data-mysql+=	poco-data-mysql>=1.15.3nb1
BUILDLINK_PKGSRCDIR.poco-data-mysql?=	../../databases/poco-data-mysql

.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.endif # POCO_DATA_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-mysql
