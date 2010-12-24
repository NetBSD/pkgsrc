# $NetBSD: buildlink3.mk,v 1.3 2010/12/24 08:10:36 asau Exp $

BUILDLINK_TREE+=	postgresql90-client

.if !defined(POSTGRESQL90_CLIENT_BUILDLINK3_MK)
POSTGRESQL90_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql90-client+=	postgresql90-client>=9.0.0
BUILDLINK_ABI_DEPENDS.postgresql90-client+=	postgresql90-client>=9.0.0
BUILDLINK_PKGSRCDIR.postgresql90-client?=	../../databases/postgresql90-client

.if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql90-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql90-client?=	${PG_SUBPREFIX}/lib
.endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql90-client=	-lpq ${BUILDLINK_LDADD.gettext}
.if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_FILES.postgresql90-client+=	$(PG_SUBPREFIX:/=)/bin/pg_config
.else
BUILDLINK_FILES.postgresql90-client+=	bin/pg_config
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL90_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql90-client
