# $NetBSD: buildlink3.mk,v 1.3 2005/03/18 19:57:31 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
POSTGRESQL80_LIB_BUILDLINK3_MK:=	${POSTGRESQL80_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql80-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql80-lib}
BUILDLINK_PACKAGES+=	postgresql80-lib

.if !empty(POSTGRESQL80_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql80-lib+=	postgresql80-lib>=8.0.0beta4
BUILDLINK_PKGSRCDIR.postgresql80-lib?=	../../databases/postgresql80-lib

BUILDLINK_INCDIRS.postgresql80-lib+=	pgsql80/include
BUILDLINK_LIBDIRS.postgresql80-lib+=	pgsql80/lib

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql80-lib=	-lpq ${BUILDLINK_LDADD.gettext}
.endif	# POSTGRESQL80_LIB_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
