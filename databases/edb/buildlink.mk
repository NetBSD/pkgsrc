# $NetBSD: buildlink.mk,v 1.1.1.1 2001/08/16 10:46:58 rh Exp $
#
# This Makefile fragment is included by packages that use edb.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.edb to the dependency pattern
#     for the version of edb desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(EDB_BUILDLINK_MK)
EDB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.edb?=	edb>=1.0.2
DEPENDS+=		${BUILDLINK_DEPENDS.edb}:../../databases/edb

EVAL_PREFIX+=		BUILDLINK_PREFIX.edb=edb
BUILDLINK_PREFIX.edb_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.edb=	include/Edb.h
BUILDLINK_FILES.edb+=	lib/libedb.*

BUILDLINK_TARGETS.edb=	edb-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.edb}

pre-configure: ${BUILDLINK_TARGETS.edb}
edb-buildlink: _BUILDLINK_USE

.endif	# EDB_BUILDLINK_MK
