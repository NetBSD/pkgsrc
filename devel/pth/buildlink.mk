# $NetBSD: buildlink.mk,v 1.8 2001/08/17 21:14:07 jlam Exp $
#
# This Makefile fragment is included by packages that use pth.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pth to the dependency pattern
#     for the version of pth desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PTH_BUILDLINK_MK)
PTH_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pth?=	pth>=1.3.2
DEPENDS+=		${BUILDLINK_DEPENDS.pth}:../../devel/pth

EVAL_PREFIX+=		BUILDLINK_PREFIX.pth=pth
BUILDLINK_PREFIX.pth_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pth=	include/pth.h
BUILDLINK_FILES.pth+=	include/pthread.h
BUILDLINK_FILES.pth+=	lib/libpth.*
BUILDLINK_FILES.pth+=	lib/libpthread.*

BUILDLINK_TARGETS.pth=	pth-buildlink
BUILDLINK_TARGETS.pth+=	pth-buildlink-config-wrapper
BUILDLINK_TARGETS.pth+=	pth-pthread-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.pth}

BUILDLINK_CONFIG.pth=			${BUILDLINK_PREFIX.pth}/bin/pth-config
BUILDLINK_CONFIG_WRAPPER.pth=		${BUILDLINK_DIR}/bin/pth-config

BUILDLINK_CONFIG.pth-pthread=		${BUILDLINK_PREFIX.pth}/bin/pthread-config
BUILDLINK_CONFIG_WRAPPER.pth-pthread=	${BUILDLINK_DIR}/bin/pthread-config

.if defined(USE_CONFIG_WRAPPER)
PTH_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.pth}
PTHREAD_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.pth-pthread}
CONFIGURE_ENV+=		PTH_CONFIG="${PTH_CONFIG}"
CONFIGURE_ENV+=		PTHREAD_CONFIG="${PTHREAD_CONFIG}"
MAKE_ENV+=		PTH_CONFIG="${PTH_CONFIG}"
MAKE_ENV+=		PTHREAD_CONFIG="${PTHREAD_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.pth}
pth-buildlink: _BUILDLINK_USE
pth-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
pth-pthread-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# PTH_BUILDLINK_MK
