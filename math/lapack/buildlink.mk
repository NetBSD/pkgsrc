# $NetBSD: buildlink.mk,v 1.1 2002/05/03 22:44:04 jtb Exp $
#
# This Makefile fragment is included by packages that use lapack.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lapack to the dependency pattern
#     for the version of lapack desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LAPACK_BUILDLINK_MK)
LAPACK_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.lapack?=	lapack>=20010201
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.lapack}:../../math/lapack

EVAL_PREFIX+=			BUILDLINK_PREFIX.lapack=lapack
BUILDLINK_PREFIX.lapack_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lapack=		lib/liblapack.*

BUILDLINK_TARGETS.lapack=		lapack-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.lapack}

pre-configure: ${BUILDLINK_TARGETS.lapack}
lapack-buildlink: _BUILDLINK_USE

.endif	# LAPACK_BUILDLINK_MK
