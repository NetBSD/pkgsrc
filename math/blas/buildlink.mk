# $NetBSD: buildlink.mk,v 1.3 2001/07/27 13:33:32 jlam Exp $
#
# This Makefile fragment is included by packages that use blas.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.blas to the dependency pattern
#     for the version of blas desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(BLAS_BUILDLINK_MK)
BLAS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.blas?=	blas>=1.0
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.blas}:../../math/blas

EVAL_PREFIX+=			BUILDLINK_PREFIX.blas=blas
BUILDLINK_PREFIX.blas_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.blas=		lib/libblas.*

BUILDLINK_TARGETS.blas=		blas-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.blas}

pre-configure: ${BUILDLINK_TARGETS.blas}
blas-buildlink: _BUILDLINK_USE

.endif	# BLAS_BUILDLINK_MK
