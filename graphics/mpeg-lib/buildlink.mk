# $NetBSD: buildlink.mk,v 1.1 2001/06/29 22:25:06 zuntum Exp $
#
# This Makefile fragment is included by packages that use mpeg.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.mpeg-lib to the dependency pattern
#     for the version of mpeg desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MPEG_BUILDLINK_MK)
MPEG_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.mpeg?=	mpeg>=1.2.1
DEPENDS+=	${BUILDLINK_DEPENDS.mpeg}:../../graphics/mpeg-lib

BUILDLINK_PREFIX.mpeg=		${LOCALBASE}
BUILDLINK_FILES.mpeg=		include/mpeg.h
BUILDLINK_FILES.mpeg+=		lib/libmpeg.*

BUILDLINK_TARGETS.mpeg=		mpeg-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.mpeg}

pre-configure: ${BUILDLINK_TARGETS.mpeg}
mpeg-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# MPEG_BUILDLINK_MK
