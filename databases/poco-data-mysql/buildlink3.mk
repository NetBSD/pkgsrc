# $NetBSD: buildlink3.mk,v 1.4 2013/02/06 23:21:08 jperkin Exp $

BUILDLINK_TREE+=	poco-data-mysql

.if !defined(POCO_DATA_MYSQL_BUILDLINK3_MK)
POCO_DATA_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-mysql+=	poco-data-mysql>=1.3.5
BUILDLINK_ABI_DEPENDS.poco-data-mysql+=	poco-data-mysql>=1.4.2p1nb1
BUILDLINK_PKGSRCDIR.poco-data-mysql?=	../../databases/poco-data-mysql

.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../databases/poco-data/buildlink3.mk"
.endif # POCO_DATA_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-mysql
