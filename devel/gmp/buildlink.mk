# $NetBSD: buildlink.mk,v 1.7 2001/07/27 13:33:23 jlam Exp $
#
# This Makefile fragment is included by packages that use gmp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gmp to the dependency pattern
#     for the version of gmp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GMP_BUILDLINK_MK)
GMP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gmp?=	gmp>=3.0
DEPENDS+=		${BUILDLINK_DEPENDS.gmp}:../../devel/gmp

EVAL_PREFIX+=		BUILDLINK_PREFIX.gmp=gmp
BUILDLINK_PREFIX.gmp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gmp=	include/gmp.h
BUILDLINK_FILES.gmp+=	lib/libgmp.*

BUILDLINK_TARGETS.gmp=	gmp-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gmp}

pre-configure: ${BUILDLINK_TARGETS.gmp}
gmp-buildlink: _BUILDLINK_USE

.endif	# GMP_BUILDLINK_MK
