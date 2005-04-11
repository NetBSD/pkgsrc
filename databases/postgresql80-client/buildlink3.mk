# $NetBSD: buildlink3.mk,v 1.1 2005/04/11 20:34:43 recht Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
POSTGRESQL80_CLIENT_BUILDLINK3_MK:=	${POSTGRESQL80_CLIENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql80-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql80-client}
BUILDLINK_PACKAGES+=	postgresql80-client

.if !empty(POSTGRESQL80_CLIENT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql80-client+=	postgresql80-client>=8.0.2
BUILDLINK_PKGSRCDIR.postgresql80-client?=	../../databases/postgresql80-client

#BUILDLINK_INCDIRS.postgresql80-client+=	pgsql80/include
#BUILDLINK_CLIENTDIRS.postgresql80-client+=	pgsql80/lib

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql80-client=	-lpq ${BUILDLINK_LDADD.gettext}

BUILDLINK_FILES.postgresql80-client+=	bin/pg_config
.endif	# POSTGRESQL80_CLIENT_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
