# $NetBSD: buildlink3.mk,v 1.3.2.1 2010/05/22 10:58:02 tron Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	postgresql83-client

.if !defined(POSTGRESQL83_CLIENT_BUILDLINK3_MK)
POSTGRESQL83_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql83-client+=	postgresql83-client>=8.3.0
BUILDLINK_ABI_DEPENDS.postgresql83-client?=	postgresql83-client>=8.3.9nb1
BUILDLINK_PKGSRCDIR.postgresql83-client?=	../../databases/postgresql83-client

.if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql83-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql83-client?=	${PG_SUBPREFIX}/lib
.endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql83-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql83-client+=	bin/pg_config

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # POSTGRESQL83_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql83-client
