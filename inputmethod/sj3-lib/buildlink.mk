# $NetBSD: buildlink.mk,v 1.2 2002/08/25 19:23:00 jlam Exp $
#
# This Makefile fragment is included by packages that use sj3.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.sj3 to the dependency pattern
#     for the version of sj3 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SJ3_BUILDLINK_MK)
SJ3_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.sj3?=	sj3-lib>=2.0.1.20nb1
DEPENDS+=	${BUILDLINK_DEPENDS.sj3}:../../inputmethod/sj3-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.sj3=sj3-lib
BUILDLINK_PREFIX.sj3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sj3=		include/sj3lib.h
BUILDLINK_FILES.sj3+=		lib/libsj3lib.a

BUILDLINK_TARGETS.sj3=	sj3-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.sj3}

pre-configure: ${BUILDLINK_TARGETS.sj3}
sj3-buildlink: _BUILDLINK_USE

.endif	# SJ3_BUILDLINK_MK
