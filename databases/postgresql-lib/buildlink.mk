# $NetBSD: buildlink.mk,v 1.6 2002/04/05 01:49:01 hubertf Exp $
#
# This Makefile fragment is included by packages that use postgresql-lib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.postgresql-lib to the dependency
#     pattern for the version of postgresql-lib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(POSTGRESQL_LIB_BUILDLINK_MK)
POSTGRESQL_LIB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

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

.include "../../security/openssl/buildlink.mk"

BUILDLINK_TARGETS.postgresql-lib=	postgresql-lib-buildlink
BUILDLINK_TARGETS+=			${BUILDLINK_TARGETS.postgresql-lib}

pre-configure: ${BUILDLINK_TARGETS.postgresql-lib}
postgresql-lib-buildlink: _BUILDLINK_USE

.endif	# POSTGRESQL_LIB_BUILDLINK_MK
