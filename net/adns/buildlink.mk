# $NetBSD: buildlink.mk,v 1.1 2001/11/19 19:39:04 jlam Exp $
#
# This Makefile fragment is included by packages that use adns.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.adns to the dependency pattern
#     for the version of adns desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ADNS_BUILDLINK_MK)
ADNS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.adns?=	adns>=1.0
DEPENDS+=	${BUILDLINK_DEPENDS.adns}:../../net/adns

EVAL_PREFIX+=			BUILDLINK_PREFIX.adns=adns
BUILDLINK_PREFIX.adns_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.adns=		include/adns.h
BUILDLINK_FILES.adns+=		lib/libadns.*

BUILDLINK_TARGETS.adns=	adns-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.adns}

pre-configure: ${BUILDLINK_TARGETS.adns}
adns-buildlink: _BUILDLINK_USE

.endif	# ADNS_BUILDLINK_MK
