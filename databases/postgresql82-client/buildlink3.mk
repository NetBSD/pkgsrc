# $NetBSD: buildlink3.mk,v 1.6.2.1 2010/05/22 11:22:54 tron Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	postgresql82-client

.if !defined(POSTGRESQL82_CLIENT_BUILDLINK3_MK)
POSTGRESQL82_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql82-client+=	postgresql82-client>=8.2.0
BUILDLINK_ABI_DEPENDS.postgresql82-client?=	postgresql82-client>=8.2.15nb1
BUILDLINK_PKGSRCDIR.postgresql82-client?=	../../databases/postgresql82-client

.if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql82-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql82-client?=	${PG_SUBPREFIX}/lib
.endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql82-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql82-client+=	bin/pg_config

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # POSTGRESQL82_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql82-client
