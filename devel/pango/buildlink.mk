# $NetBSD: buildlink.mk,v 1.3 2002/06/30 01:51:30 jschauma Exp $
#
# This Makefile fragment is included by packages that use pango.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pango to the dependency pattern
#     for the version of pango desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PANGO_BUILDLINK_MK)
PANGO_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pango?=	pango>=1.0.3
DEPENDS+=	${BUILDLINK_DEPENDS.pango}:../../devel/pango

EVAL_PREFIX+=		BUILDLINK_PREFIX.pango=pango
BUILDLINK_PREFIX.pango_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pango=	include/pango-1.0/*/*
BUILDLINK_FILES.pango+=	include/pango-1.0/*
BUILDLINK_FILES.pango+=	lib/libpango*-1.0.*

.include "../../devel/pkgconfig/buildlink.mk"

BUILDLINK_TARGETS.pango=	pango-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.pango}

pre-configure: ${BUILDLINK_TARGETS.pango}
pango-buildlink: _BUILDLINK_USE

.endif	# PANGO_BUILDLINK_MK
