# $NetBSD: buildlink.mk,v 1.2 2002/07/08 02:14:41 wiz Exp $
#
# This Makefile fragment is included by packages that use the library
# provided by libart2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libart2 to the dependency
#     pattern for the version of libart2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBART2_BUILDLINK_MK)
LIBART2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libart2?=	libart2>=2.3.8
DEPENDS+=	${BUILDLINK_DEPENDS.libart2}:../../graphics/libart2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libart2=libart2
BUILDLINK_PREFIX.libart2=	${LOCALBASE}
BUILDLINK_FILES.libart2=	include/libart-2.0/libart_lgpl/*
BUILDLINK_FILES.libart2+=	lib/libart_lgpl_2.*

BUILDLINK_TARGETS.libart2=	libart2-buildlink
BUILDLINK_TARGETS.libart2+=	libart2-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libart2}

BUILDLINK_CONFIG.libart2=	\
	${BUILDLINK_PREFIX.libart2}/bin/libart2-config
BUILDLINK_CONFIG_WRAPPER.libart2=	\
	${BUILDLINK_DIR}/bin/libart2-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libart2}|${BUILDLINK_CONFIG.libart2}|g"
.if defined(USE_CONFIG_WRAPPER)
LIBART2_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.libart2}
CONFIGURE_ENV+=		LIBART2_CONFIG="${LIBART2_CONFIG}"
MAKE_ENV+=		LIBART2_CONFIG="${LIBART2_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libart2}
libart2-buildlink: _BUILDLINK_USE
libart2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBART2_BUILDLINK_MK
