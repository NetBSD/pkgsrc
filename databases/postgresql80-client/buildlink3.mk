# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:35 joerg Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
POSTGRESQL80_CLIENT_BUILDLINK3_MK:=	${POSTGRESQL80_CLIENT_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql80-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql80-client}
BUILDLINK_PACKAGES+=	postgresql80-client

.if !empty(POSTGRESQL80_CLIENT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql80-client+=		postgresql80-client>=8.0.2
BUILDLINK_RECOMMENDED.postgresql80-client?=	postgresql80-client>=8.0.5nb1
BUILDLINK_PKGSRCDIR.postgresql80-client?=	../../databases/postgresql80-client

.  if defined(PG_SUBPREFIX) && !empty(PG_SUBPREFIX)
BUILDLINK_INCDIRS.postgresql80-client?=	${PG_SUBPREFIX}/include
BUILDLINK_LIBDIRS.postgresql80-client?=	${PG_SUBPREFIX}/lib
.  endif

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql80-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql80-client+=	bin/pg_config
.endif	# POSTGRESQL80_CLIENT_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
