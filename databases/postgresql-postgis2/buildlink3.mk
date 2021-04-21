# $NetBSD: buildlink3.mk,v 1.16 2021/04/21 11:40:15 adam Exp $

BUILDLINK_TREE+=	postgresql-postgis

.if !defined(POSTGRESQL_POSTGIS_BUILDLINK3_MK)
POSTGRESQL_POSTGIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql-postgis+=	postgresql${PGSQL_VERSION}-postgis>=2.0
BUILDLINK_ABI_DEPENDS.postgresql-postgis?=	postgresql13-postgis>=3.1.1nb4
BUILDLINK_PKGSRCDIR.postgresql-postgis?=	../../databases/postgresql-postgis2

PGSQL_VERSIONS_ACCEPTED=	10 96 95

.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.endif	# POSTGRESQL_POSTGIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql-postgis
