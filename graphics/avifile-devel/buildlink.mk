# $NetBSD: buildlink.mk,v 1.1 2001/07/26 15:23:14 zuntum Exp $
#
# This Makefile fragment is included by packages that use avifile-devel.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.avifile-devel to the dependency pattern
#     for the version of avifile-devel desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(AVIFILE-DEVEL_BUILDLINK_MK)
AVIFILE-DEVEL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.avifile-devel?=	avifile>=0.6
DEPENDS+=	${BUILDLINK_DEPENDS.avifile-devel}:../../graphics/avifile-devel

EVAL_PREFIX+=			BUILDLINK_PREFIX.avifile-devel=avifile
BUILDLINK_FILES.avifile-devel=	lib/libaviplay.*
BUILDLINK_FILES.avifile-devel+=	lib/avifile/*
BUILDLINK_FILES.avifile-devel+=	include/avifile/*
BUILDLINK_FILES.avifile-devel+=	include/avifile/wine/*

BUILDLINK_TARGETS.avifile-devel=	avifile-devel-buildlink
BUILDLINK_TARGETS.avifile-devel+=	avifile-devel-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.avifile-devel}

BUILDLINK_CONFIG.avifile-devel=	${BUILDLINK_PREFIX.avifile-devel}/bin/avifile-config
BUILDLINK_CONFIG_WRAPPER.avifile-devel=${BUILDLINK_DIR}/bin/avifile-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
AVIFILE-DEVEL_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.avifile-devel}
CONFIGURE_ENV+=			AVIFILE-DEVEL_CONFIG="${AVIFILE-DEVEL_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.avifile-devel}
avifile-devel-buildlink: _BUILDLINK_USE
avifile-devel-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# AVIFILE-DEVEL_BUILDLINK_MK
