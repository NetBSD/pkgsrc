# $NetBSD: buildlink2.mk,v 1.4 2004/03/26 02:27:37 wiz Exp $

.if !defined(POSTGRESQL_LIB_BUILDLINK2_MK)
POSTGRESQL_LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			postgresql-lib
BUILDLINK_DEPENDS.postgresql-lib?=	postgresql-lib>=7.3.1
BUILDLINK_RECOMMENDED.postgresql-lib?=	postgresql-lib>=7.3.4nb2
BUILDLINK_PKGSRCDIR.postgresql-lib?=	../../databases/postgresql-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.postgresql-lib=postgresql-lib
BUILDLINK_PREFIX.postgresql-lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.postgresql-lib=		include/postgresql/*/*/*.h
BUILDLINK_FILES.postgresql-lib+=	include/postgresql/*/*.h
BUILDLINK_FILES.postgresql-lib+=	include/postgresql/*.h
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/*/*/*.h
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/*/*.h
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/*.h
BUILDLINK_FILES.postgresql-lib+=	lib/libecpg.*
BUILDLINK_FILES.postgresql-lib+=	lib/libpq.*

.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	postgresql-lib-buildlink

postgresql-lib-buildlink: _BUILDLINK_USE

.endif	# POSTGRESQL_LIB_BUILDLINK2_MK
