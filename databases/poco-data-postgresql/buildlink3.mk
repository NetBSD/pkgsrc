# $NetBSD: buildlink3.mk,v 1.2 2026/09/02 19:01:18 wiz Exp $

BUILDLINK_TREE+=	poco-data-postgresql

.if !defined(POCO_DATA_POSTGRESQL_BUILDLINK3_MK)
POCO_DATA_POSTGRESQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-postgresql+=	poco-data-postgresql>=1.15.3
BUILDLINK_ABI_DEPENDS.poco-data-postgresql?=	poco-data-postgresql>=1.15.3nb1
BUILDLINK_PKGSRCDIR.poco-data-postgresql?=	../../databases/poco-data-postgresql

.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.endif	# POCO_DATA_POSTGRESQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-postgresql
