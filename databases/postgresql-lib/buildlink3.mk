# $NetBSD: buildlink3.mk,v 1.5 2004/03/05 19:25:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POSTGRESQL_LIB_BUILDLINK3_MK:=	${POSTGRESQL_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql-lib}
BUILDLINK_PACKAGES+=	postgresql-lib

.if !empty(POSTGRESQL_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql-lib+=	postgresql-lib>=7.3.1
BUILDLINK_PKGSRCDIR.postgresql-lib?=	../../databases/postgresql-lib
BUILDLINK_INCDIRS.postgresql-lib?=	include/postgresql

.include "../../security/openssl/buildlink3.mk"

.endif	# POSTGRESQL_LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
