# $NetBSD: buildlink.mk,v 1.5 2001/11/19 20:12:23 jlam Exp $
#
# This Makefile fragment is included by packages that use rsaref.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.rsaref to the dependency pattern
#     for the version of rsaref desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RSAREF_BUILDLINK_MK)
RSAREF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.rsaref?=	rsaref-2.0p3
DEPENDS+=	${BUILDLINK_DEPENDS.rsaref}:../../security/rsaref

EVAL_PREFIX+=				BUILDLINK_PREFIX.rsaref=rsaref
BUILDLINK_PREFIX.rsaref_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rsaref=			include/rsaref/*.h
BUILDLINK_FILES.rsaref+=		lib/librsaref.*

BUILDLINK_TARGETS.rsaref=	rsaref-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.rsaref}

pre-configure: ${BUILDLINK_TARGETS.rsaref}
rsaref-buildlink: _BUILDLINK_USE

.endif	# RSAREF_BUILDLINK_MK
