# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:06 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	postgresql81-client

.if !defined(POSTGRESQL81_CLIENT_BUILDLINK3_MK)
POSTGRESQL81_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql81-client+=		postgresql81-client>=8.1.0
BUILDLINK_ABI_DEPENDS.postgresql81-client?=	postgresql81-client>=8.1.11nb1
BUILDLINK_PKGSRCDIR.postgresql81-client?=	../../databases/postgresql81-client

.  if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql81-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql81-client?=	${PG_SUBPREFIX}/lib
.  endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql81-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql81-client+=	bin/pg_config

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # POSTGRESQL81_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql81-client
