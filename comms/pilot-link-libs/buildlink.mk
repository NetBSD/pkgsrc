# $NetBSD: buildlink.mk,v 1.6 2002/09/10 16:06:36 wiz Exp $
#
# This Makefile fragment is included by packages that use pilot-link-libs.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pilot-link-libs to the dependency
#     pattern for the version of pilot-link-libs desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PILOT_LINK_LIBS_BUILDLINK_MK)
PILOT_LINK_LIBS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pilot-link-libs?=	pilot-link-libs>=0.9.5nb3
DEPENDS+=	${BUILDLINK_DEPENDS.pilot-link-libs}:../../comms/pilot-link-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.pilot-link-libs=pilot-link-libs
BUILDLINK_PREFIX.pilot-link-libs_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pilot-link-libs=	include/pi-*.*
BUILDLINK_FILES.pilot-link-libs+=	lib/libpicc.*
BUILDLINK_FILES.pilot-link-libs+=	lib/libpisock.*

.include "../../converters/libiconv/buildlink.mk"

BUILDLINK_TARGETS.pilot-link-libs=	pilot-link-libs-buildlink
BUILDLINK_TARGETS+=			${BUILDLINK_TARGETS.pilot-link-libs}

pre-configure: ${BUILDLINK_TARGETS.pilot-link-libs}
pilot-link-libs-buildlink: _BUILDLINK_USE

.endif	# PILOT_LINK_LIBS_BUILDLINK_MK
