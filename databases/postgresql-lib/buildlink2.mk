# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:35 jlam Exp $
#
# This Makefile fragment is included by packages that use postgresql-lib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.postgresql-lib to the dependency
#     pattern for the version of postgresql-lib desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(POSTGRESQL_LIB_BUILDLINK2_MK)
POSTGRESQL_LIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.postgresql-lib?=	postgresql-{6.5.3*,7.0*,lib-*}
DEPENDS+=	${BUILDLINK_DEPENDS.postgresql-lib}:../../databases/postgresql-lib

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
