# $NetBSD: buildlink.mk,v 1.1 2002/05/03 22:59:53 jtb Exp $
#
# This Makefile fragment is included by packages that use udunits.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.udunits to the dependency pattern
#     for the version of udunits desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(UDUNITS_BUILDLINK_MK)
UDUNITS_BUILDLINK_MK=		# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.udunits?=	udunits>=1.11.7
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.udunits}:../../math/udunits

EVAL_PREFIX+=			BUILDLINK_PREFIX.udunits=udunits
BUILDLINK_PREFIX.udunits_DEFAULT=${LOCALBASE}
BUILDLINK_FILES.udunits=	lib/libudunits.*
BUILDLINK_FILES.udunits+=	lib/libudport.*
BUILDLINK_FILES.udunits+=	include/udunits.h
BUILDLINK_FILES.udunits+=	include/udunits.inc

BUILDLINK_TARGETS.udunits=	udunits-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.udunits}

pre-configure: ${BUILDLINK_TARGETS.udunits}
udunits-buildlink: _BUILDLINK_USE

.endif	# UDUNITS_BUILDLINK_MK
