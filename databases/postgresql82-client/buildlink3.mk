# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/12/09 15:35:02 adam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
POSTGRESQL82_CLIENT_BUILDLINK3_MK:=	${POSTGRESQL82_CLIENT_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql82-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql82-client}
BUILDLINK_PACKAGES+=	postgresql82-client
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}postgresql82-client

.if !empty(POSTGRESQL82_CLIENT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.postgresql82-client+=	postgresql82-client>=8.2.0
BUILDLINK_PKGSRCDIR.postgresql82-client?=	../../databases/postgresql82-client

.  if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql82-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql82-client?=	${PG_SUBPREFIX}/lib
.  endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql82-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql82-client+=	bin/pg_config
.endif	# POSTGRESQL82_CLIENT_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
