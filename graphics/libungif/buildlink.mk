# $NetBSD: buildlink.mk,v 1.5 2001/07/27 13:33:30 jlam Exp $
#
# This Makefile fragment is included by packages that use libungif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libungif to the dependency pattern
#     for the version of libungif desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBUNGIF_BUILDLINK_MK)
LIBUNGIF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libungif?=	libungif>=4.1.0
DEPENDS+=	${BUILDLINK_DEPENDS.libungif}:../../graphics/libungif

EVAL_PREFIX+=			BUILDLINK_PREFIX.libungif=libungif
BUILDLINK_PREFIX.libungif_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libungif=	include/gif_lib.h
BUILDLINK_FILES.libungif+=	lib/libgif.*
BUILDLINK_FILES.libungif+=	lib/libungif.*

BUILDLINK_TARGETS.libungif=	libungif-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libungif}

pre-configure: ${BUILDLINK_TARGETS.libungif}
libungif-buildlink: _BUILDLINK_USE

.endif	# LIBUNGIF_BUILDLINK_MK
