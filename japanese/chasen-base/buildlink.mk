# $NetBSD: buildlink.mk,v 1.1 2001/09/09 05:15:14 jlam Exp $
#
# This Makefile fragment is included by packages that use chasen-base.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.chasen-base to the dependency pattern
#     for the version of chasen-base desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CHASEN_BASE_BUILDLINK_MK)
CHASEN_BASE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.chasen-base?=	chasen-base>=2.2.5
DEPENDS+=	${BUILDLINK_DEPENDS.chasen-base}:../../japanese/chasen-base

EVAL_PREFIX+=	BUILDLINK_PREFIX.chasen-base=chasen-base
BUILDLINK_PREFIX.chasen-base_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.chasen-base=	include/chasen.h
BUILDLINK_FILES.chasen-base+=	lib/libchasen.*

BUILDLINK_TARGETS.chasen-base=	chasen-base-buildlink
BUILDLINK_TARGETS.chasen-base+=	chasen-base-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.chasen-base}

BUILDLINK_CONFIG.chasen-base=	\
	${BUILDLINK_PREFIX.chasen-base}/bin/chasen-config
BUILDLINK_CONFIG_WRAPPER.chasen-base=	\
	${BUILDLINK_DIR}/bin/chasen-config

.if defined(USE_CONFIG_WRAPPER)
CHASEN_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.chasen-base}
CONFIGURE_ENV+=		CHASEN_CONFIG="${CHASEN_BASE_CONFIG}"
MAKE_ENV+=		CHASEN_CONFIG="${CHASEN_BASE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.chasen-base}
chasen-base-buildlink: _BUILDLINK_USE
chasen-base-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# CHASEN_BASE_BUILDLINK_MK
