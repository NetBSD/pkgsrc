# $NetBSD: buildlink.mk,v 1.1 2001/10/16 16:24:35 jlam Exp $
#
# This Makefile fragment is included by packages that use sqlite.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.sqlite to the dependency pattern
#     for the version of sqlite desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SQLITE_BUILDLINK_MK)
SQLITE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.sqlite?=	sqlite>=2.0.5
DEPENDS+=	${BUILDLINK_DEPENDS.sqlite}:../../databases/sqlite

EVAL_PREFIX+=				BUILDLINK_PREFIX.sqlite=sqlite
BUILDLINK_PREFIX.sqlite_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sqlite=			include/sqlite.h
BUILDLINK_FILES.sqlite+=		lib/libsqlite.*

BUILDLINK_TARGETS.sqlite=	sqlite-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.sqlite}

pre-configure: ${BUILDLINK_TARGETS.sqlite}
sqlite-buildlink: _BUILDLINK_USE

.endif	# SQLITE_BUILDLINK_MK
