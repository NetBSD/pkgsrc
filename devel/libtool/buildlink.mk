# $NetBSD: buildlink.mk,v 1.1 2001/06/20 21:33:01 jlam Exp $
#
# This Makefile fragment is included by packages that use ltdl.
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LTDL_BUILDLINK_MK)
LTDL_BUILDLINK_MK=	# defined

DEPENDS+=		libtool>=${LIBTOOL_REQD}:../../devel/libtool

BUILDLINK_PREFIX.ltdl=	${LOCALBASE}
BUILDLINK_FILES.ltdl=	include/ltdl.h
BUILDLINK_FILES.ltdl+=	lib/libltdl.*

BUILDLINK_TARGETS.ltdl=	ltdl-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.ltdl}

pre-configure: ${BUILDLINK_TARGETS.ltdl}
ltdl-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# LTDL_BUILDLINK_MK
