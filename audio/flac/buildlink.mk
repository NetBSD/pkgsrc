# $NetBSD: buildlink.mk,v 1.2 2002/09/04 19:34:14 jlam Exp $
#
# This Makefile fragment is included by packages that use flac.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.flac to the dependency pattern
#     for the version of flac desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FLAC_BUILDLINK_MK)
FLAC_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.flac?=	flac>=1.0.3
DEPENDS+=	${BUILDLINK_DEPENDS.flac}:../../audio/flac

EVAL_PREFIX+=			BUILDLINK_PREFIX.flac=flac
BUILDLINK_PREFIX.flac_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.flac=	include/FLAC/*
BUILDLINK_FILES.flac+=	lib/libFLAC.*

BUILDLINK_TARGETS.flac=	flac-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.flac}

pre-configure: ${BUILDLINK_TARGETS.flac}
flac-buildlink: _BUILDLINK_USE

.endif	# LIBVORBIS_BUILDLINK_MK
