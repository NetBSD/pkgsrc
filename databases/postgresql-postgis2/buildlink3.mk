# $NetBSD: buildlink3.mk,v 1.5 2015/10/24 21:18:12 joerg Exp $

BUILDLINK_TREE+=	postgresql-postgis

.if !defined(POSTGRESQL_POSTGIS_BUILDLINK3_MK)
POSTGRESQL_POSTGIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql-postgis+=	postgresql${PGSQL_VERSION}-postgis>=1.4
BUILDLINK_ABI_DEPENDS.postgresql-postgis?=	postgresql${PGSQL_VERSION}-postgis>=2.1.4nb2
BUILDLINK_PKGSRCDIR.postgresql-postgis?=	../../databases/postgresql-postgis2

PGSQL_VERSIONS_ACCEPTED=	94 93 92 91

.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.endif	# POSTGRESQL_POSTGIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql-postgis
