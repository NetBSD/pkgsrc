# $NetBSD: buildlink.mk,v 1.1 2001/09/09 05:30:55 jlam Exp $
#
# This Makefile fragment is included by packages that use chasen.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.chasen to the dependency pattern
#     for the version of chasen desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CHASEN_BUILDLINK_MK)
CHASEN_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.chasen?=	chasen>=2.0
DEPENDS+=	${BUILDLINK_DEPENDS.chasen}:../../japanese/chasen

EVAL_PREFIX+=	BUILDLINK_PREFIX.chasen=chasen
BUILDLINK_PREFIX.chasen_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.chasen=			include/chasen.h
BUILDLINK_FILES.chasen+=		lib/libchasen.*

BUILDLINK_TARGETS.chasen=	chasen-buildlink
BUILDLINK_TARGETS.chasen+=	chasen-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.chasen}

BUILDLINK_CONFIG.chasen=	\
	${BUILDLINK_PREFIX.chasen}/bin/chasen-config
BUILDLINK_CONFIG_WRAPPER.chasen=	\
	${BUILDLINK_DIR}/bin/chasen-config

.if defined(USE_CONFIG_WRAPPER)
CHASEN_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.chasen}
CONFIGURE_ENV+=		CHASEN_CONFIG="${CHASEN_CONFIG}"
MAKE_ENV+=		CHASEN_CONFIG="${CHASEN_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.chasen}
chasen-buildlink: _BUILDLINK_USE
chasen-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# CHASEN_BUILDLINK_MK
