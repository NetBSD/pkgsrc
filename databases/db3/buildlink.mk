# $NetBSD: buildlink.mk,v 1.5 2001/10/23 07:26:41 lukem Exp $
#
# This Makefile fragment is included by packages that use db3.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.db3 to the dependency pattern
#     for the version of db3 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(DB3_BUILDLINK_MK)
DB3_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.db3?=	db3>=2.9.2
DEPENDS+=		${BUILDLINK_DEPENDS.db3}:../../databases/db3

EVAL_PREFIX+=		BUILDLINK_PREFIX.db3=db3
BUILDLINK_PREFIX.db3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.db3=	include/db3/db_cxx.h
BUILDLINK_FILES.db3+=	include/db3/db.h
BUILDLINK_FILES.db3+=	lib/libdb3.*
BUILDLINK_FILES.db3+=	lib/libdb3_cxx.*

BUILDLINK_TARGETS.db3=	db3-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.db3}

pre-configure: ${BUILDLINK_TARGETS.db3}
db3-buildlink: _BUILDLINK_USE

.endif	# DB3_BUILDLINK_MK
