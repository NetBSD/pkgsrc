# $NetBSD: buildlink.mk,v 1.1 2001/12/26 00:32:01 zuntum Exp $
#
# This Makefile fragment is included by packages that use lame.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lame to the dependency pattern
#     for the version of lame desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LAME_BUILDLINK_MK)
LAME_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.lame?=	lame>=3.89
DEPENDS+=		${BUILDLINK_DEPENDS.lame}:../../audio/lame

EVAL_PREFIX+=		BUILDLINK_PREFIX.lame=lame
BUILDLINK_PREFIX.lame=	${LOCALBASE}
BUILDLINK_FILES.lame=	include/lame/lame.h

BUILDLINK_TARGETS.lame=	lame-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.lame}

pre-configure: ${BUILDLINK_TARGETS.lame}
lame-buildlink: _BUILDLINK_USE

.endif	# LAME_BUILDLINK_MK
