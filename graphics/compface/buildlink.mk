# $NetBSD: buildlink.mk,v 1.1.1.1 2002/07/19 01:13:52 hubertf Exp $
#
# This Makefile fragment is included by packages that use COMPFACE.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.compface to the dependency pattern
#     for the version of COMPFACE desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(COMPFACE_BUILDLINK_MK)
COMPFACE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.compface?=	compface>=1.4
DEPENDS+=	${BUILDLINK_DEPENDS.compface}:../../graphics/compface

EVAL_PREFIX+=		BUILDLINK_PREFIX.compface=compface
BUILDLINK_PREFIX.compface_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.compface+=	include/compface.h
BUILDLINK_FILES.compface+=	lib/libcompface.*

BUILDLINK_TARGETS.compface=	compface-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.compface}

pre-configure: ${BUILDLINK_TARGETS.compface}
compface-buildlink: _BUILDLINK_USE

.endif	# COMPFACE_BUILDLINK_MK
