# $NetBSD: buildlink.mk,v 1.4 2001/07/27 13:33:20 jlam Exp $
#
# This Makefile fragment is included by packages that use libsidplay.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libsidplay to the dependency pattern
#     for the version of libsidplay desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBSIDPLAY_BUILDLINK_MK)
LIBSIDPLAY_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libsidplay?=	libsidplay>=1.36.38
DEPENDS+=	${BUILDLINK_DEPENDS.libsidplay}:../../audio/libsidplay

EVAL_PREFIX+=			BUILDLINK_PREFIX.libsidplay=libsidplay
BUILDLINK_PREFIX.libsidplay_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsidplay=	include/sidplay/*
BUILDLINK_FILES.libsidplay+=	lib/libsidplay.*

BUILDLINK_TARGETS.libsidplay=	libsidplay-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libsidplay}

pre-configure: ${BUILDLINK_TARGETS.libsidplay}
libsidplay-buildlink: _BUILDLINK_USE

.endif	# LIBSIDPLAY_BUILDLINK_MK
