# $NetBSD: buildlink.mk,v 1.1 2001/10/09 19:20:33 jlam Exp $
#
# This Makefile fragment is included by packages that use mhash.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.mhash to the dependency pattern
#     for the version of mhash desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MHASH_BUILDLINK_MK)
MHASH_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.mhash?=	mhash>=0.8.3
DEPENDS+=	${BUILDLINK_DEPENDS.mhash}:../../security/mhash

EVAL_PREFIX+=			BUILDLINK_PREFIX.mhash=mhash
BUILDLINK_PREFIX.mhash_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mhash=		include/mhash.h
BUILDLINK_FILES.mhash+=		lib/libmhash.*

BUILDLINK_TARGETS.mhash=	mhash-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.mhash}

pre-configure: ${BUILDLINK_TARGETS.mhash}
mhash-buildlink: _BUILDLINK_USE

.endif	# MHASH_BUILDLINK_MK
