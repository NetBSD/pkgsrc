# $NetBSD: buildlink.mk,v 1.1 2001/09/14 07:40:36 jlam Exp $
#
# This Makefile fragment is included by packages that use expat.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.expat to the dependency pattern
#     for the version of expat desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(EXPAT_BUILDLINK_MK)
EXPAT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.expat?=	expat>=1.95.2
DEPENDS+=	${BUILDLINK_DEPENDS.expat}:../../textproc/expat

EVAL_PREFIX+=			BUILDLINK_PREFIX.expat=expat
BUILDLINK_PREFIX.expat_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.expat=		include/expat.h
BUILDLINK_FILES.expat+=		lib/libexpat.*

BUILDLINK_TARGETS.expat=	expat-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.expat}

pre-configure: ${BUILDLINK_TARGETS.expat}
expat-buildlink: _BUILDLINK_USE

.endif	# EXPAT_BUILDLINK_MK
