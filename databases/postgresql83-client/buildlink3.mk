# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/03/04 12:42:53 adam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
POSTGRESQL83_CLIENT_BUILDLINK3_MK:=	${POSTGRESQL83_CLIENT_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	postgresql83-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql83-client}
BUILDLINK_PACKAGES+=	postgresql83-client
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}postgresql83-client

.if ${POSTGRESQL83_CLIENT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.postgresql83-client+=	postgresql83-client>=8.3.0
BUILDLINK_ABI_DEPENDS.postgresql83-client?=	postgresql83-client>=8.3.0
BUILDLINK_PKGSRCDIR.postgresql83-client?=	../../databases/postgresql83-client

.  if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql83-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql83-client?=	${PG_SUBPREFIX}/lib
.  endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql83-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql83-client+=	bin/pg_config
.endif	# POSTGRESQL83_CLIENT_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
