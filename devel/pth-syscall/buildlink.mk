# $NetBSD: buildlink.mk,v 1.2 2002/07/18 11:22:01 agc Exp $
#
# This Makefile fragment is included by packages that use pth-syscall.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pth-syscall to the dependency pattern
#     for the version of pth desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PTH_SYSCALL_BUILDLINK_MK)
PTH_SYSCALL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pth-syscall?=	pth-syscall>=1.4.1
DEPENDS+=		${BUILDLINK_DEPENDS.pth-syscall}:../../devel/pth-syscall

EVAL_PREFIX+=		PTH_SYSCALL_PREFIX=pth-syscall
PTH_SYSCALL_PREFIX_DEFAULT=	${LOCALBASE}
BUILDLINK_PREFIX.pth-syscall=	${PTH_SYSCALL_PREFIX}/pth-syscall
BUILDLINK_FILES.pth-syscall=	include/pth.h
BUILDLINK_FILES.pth-syscall+=	include/pthread.h
BUILDLINK_FILES.pth-syscall+=	lib/libpth.*
BUILDLINK_FILES.pth-syscall+=	lib/libpthread.*

BUILDLINK_TARGETS.pth-syscall=	pth-syscall-buildlink
BUILDLINK_TARGETS.pth-syscall+=	pth-syscall-buildlink-config-wrapper
BUILDLINK_TARGETS.pth-syscall+=	pth-syscall-pthread-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.pth-syscall}

BUILDLINK_CONFIG.pth-syscall=			${BUILDLINK_PREFIX.pth-syscall}/bin/pth-config
BUILDLINK_CONFIG_WRAPPER.pth-syscall=		${BUILDLINK_DIR}/bin/pth-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.pth-syscall}|${BUILDLINK_CONFIG.pth-syscall}|g"

BUILDLINK_CONFIG.pth-syscall-pthread=		${BUILDLINK_PREFIX.pth-syscall}/bin/pthread-config
BUILDLINK_CONFIG_WRAPPER.pth-syscall-pthread=	${BUILDLINK_DIR}/bin/pthread-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.pth-syscall-pthread}|${BUILDLINK_CONFIG.pth-syscall-pthread}|g"

LDFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.pth-syscall}/lib

.if defined(USE_CONFIG_WRAPPER)
PTH_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.pth-syscall}
PTHREAD_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.pth-syscall-pthread}
CONFIGURE_ENV+=		PTH_CONFIG="${PTH_CONFIG}"
CONFIGURE_ENV+=		PTHREAD_CONFIG="${PTHREAD_CONFIG}"
MAKE_ENV+=		PTH_CONFIG="${PTH_CONFIG}"
MAKE_ENV+=		PTHREAD_CONFIG="${PTHREAD_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.pth-syscall}
pth-syscall-buildlink: _BUILDLINK_USE
pth-syscall-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
pth-syscall-pthread-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# PTH_SYSCALL_BUILDLINK_MK
