# $NetBSD: buildlink.mk,v 1.1 2001/11/19 19:45:39 jlam Exp $
#
# This Makefile fragment is included by packages that use boehm-gc.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.boehm-gc to the dependency pattern
#     for the version of boehm-gc desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(BOEHM_GC_BUILDLINK_MK)
BOEHM_GC_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

# This adds a build-dependency as boehm-gc only has a static library.
BUILDLINK_DEPENDS.boehm-gc?=	boehm-gc>=5.3
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.boehm-gc}:../../devel/boehm-gc

EVAL_PREFIX+=				BUILDLINK_PREFIX.boehm-gc=boehm-gc
BUILDLINK_PREFIX.boehm-gc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.boehm-gc=		include/gc.h
BUILDLINK_FILES.boehm-gc+=		include/gc_cpp.h
BUILDLINK_FILES.boehm-gc+=		lib/libgc.a
BUILDLINK_FILES.boehm-gc+=		lib/libleak.a

BUILDLINK_TARGETS.boehm-gc=	boehm-gc-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.boehm-gc}

pre-configure: ${BUILDLINK_TARGETS.boehm-gc}
boehm-gc-buildlink: _BUILDLINK_USE

.endif	# BOEHM_GC_BUILDLINK_MK
