# $NetBSD: buildlink3.mk,v 1.3 2004/06/27 16:38:32 recht Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POSTGRESQL_LIB_BUILDLINK3_MK:=	${POSTGRESQL_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql-lib}
BUILDLINK_PACKAGES+=	postgresql-lib

.if !empty(POSTGRESQL_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql-lib+=	postgresql-lib>=7.4.3
BUILDLINK_PKGSRCDIR.postgresql-lib?=	../../databases/postgresql74-lib
BUILDLINK_INCDIRS.postgresql-lib?=	include/postgresql
.endif	# POSTGRESQL_LIB_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
