# $NetBSD: buildlink3.mk,v 1.2 2005/03/18 19:57:31 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POSTGRESQL73_LIB_BUILDLINK3_MK:=	${POSTGRESQL73_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql73-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql73-lib}
BUILDLINK_PACKAGES+=	postgresql73-lib

.if !empty(POSTGRESQL73_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql73-lib+=	postgresql73-lib>=7.3.6
BUILDLINK_PKGSRCDIR.postgresql73-lib?=	../../databases/postgresql73-lib
BUILDLINK_INCDIRS.postgresql73-lib?=	include/postgresql
BUILDLINK_FILES.postgresql73-lib+=	include/pgsql/*
BUILDLINK_FILES.postgresql73-lib+=	include/pgsql/server/*.h
BUILDLINK_FILES.postgresql73-lib+=	include/pgsql/server/utils/*.h

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql73-lib=		-lpq
.endif	# POSTGRESQL73_LIB_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
