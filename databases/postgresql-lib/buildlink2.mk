# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:25 jlam Exp $

.if !defined(POSTGRESQL_LIB_BUILDLINK2_MK)
POSTGRESQL_LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			postgresql-lib
BUILDLINK_DEPENDS.postgresql-lib?=	postgresql-{6.5.3*,7.0*,lib-*}
BUILDLINK_PKGSRCDIR.postgresql-lib?=	../../databases/postgresql-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.postgresql-lib=postgresql-lib
BUILDLINK_PREFIX.postgresql-lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.postgresql-lib=		include/pgsql/*/*/*.h
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/*/*.h
BUILDLINK_FILES.postgresql-lib+=	include/pgsql/*.h
BUILDLINK_FILES.postgresql-lib+=	lib/libecpg.*
BUILDLINK_FILES.postgresql-lib+=	lib/libpgeasy.*
BUILDLINK_FILES.postgresql-lib+=	lib/libpq++.*
BUILDLINK_FILES.postgresql-lib+=	lib/libpq.*

.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	postgresql-lib-buildlink

postgresql-lib-buildlink: _BUILDLINK_USE

.endif	# POSTGRESQL_LIB_BUILDLINK2_MK
