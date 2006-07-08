# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:40 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
POSTGRESQL81_CLIENT_BUILDLINK3_MK:=	${POSTGRESQL81_CLIENT_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql81-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql81-client}
BUILDLINK_PACKAGES+=	postgresql81-client
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}postgresql81-client

.if !empty(POSTGRESQL81_CLIENT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.postgresql81-client+=		postgresql81-client>=8.1.0
BUILDLINK_PKGSRCDIR.postgresql81-client?=	../../databases/postgresql81-client

.  if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql81-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql81-client?=	${PG_SUBPREFIX}/lib
.  endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql81-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql81-client+=	bin/pg_config
.endif	# POSTGRESQL81_CLIENT_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
