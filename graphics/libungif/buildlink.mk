# $NetBSD: buildlink.mk,v 1.1 2001/06/16 19:23:19 jlam Exp $
#
# This Makefile fragment is included by packages that use libungif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define LIBUNGIF_REQD to the version of libungif desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBUNGIF_BUILDLINK_MK)
LIBUNGIF_BUILDLINK_MK=	# defined

LIBUNGIF_REQD?=		4.1.0
DEPENDS+=		libungif>=${LIBUNGIF_REQD}:../../graphics/libungif

BUILDLINK_PREFIX.libungif=	${LOCALBASE}
BUILDLINK_FILES.libungif=	include/gif_lib.h
BUILDLINK_FILES.libungif+=	lib/libgif.*
BUILDLINK_FILES.libungif+=	lib/libungif.*

BUILDLINK_TARGETS.libungif=	libungif-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libungif}

pre-configure: ${BUILDLINK_TARGETS.libungif}
libungif-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# LIBUNGIF_BUILDLINK_MK
