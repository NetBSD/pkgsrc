# $NetBSD: buildlink3.mk,v 1.9 2004/05/09 06:11:51 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POSTGRESQL_LIB_BUILDLINK3_MK:=	${POSTGRESQL_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql-lib}
BUILDLINK_PACKAGES+=	postgresql-lib

.if !empty(POSTGRESQL_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql-lib+=	postgresql-lib>=7.3.1
BUILDLINK_RECOMMENDED.postgresql-lib?=	postgresql-lib>=7.3.4nb2
BUILDLINK_PKGSRCDIR.postgresql-lib?=	../../databases/postgresql-lib
BUILDLINK_INCDIRS.postgresql-lib?=	include/postgresql
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/*
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/server/*.h
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/server/utils/*.h
.endif	# POSTGRESQL_LIB_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
