# $NetBSD: buildlink.mk,v 1.3 2001/07/27 13:33:27 jlam Exp $
#
# This Makefile fragment is included by packages that use fnlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.fnlib to the dependency pattern
#     for the version of fnlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FNLIB_BUILDLINK_MK)
FNLIB_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.fnlib?=	fnlib>=0.5
DEPENDS+=	${BUILDLINK_DEPENDS.fnlib}:../../graphics/fnlib

EVAL_PREFIX+=		BUILDLINK_PREFIX.fnlib=fnlib
BUILDLINK_PREFIX.fnlib_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.fnlib=	include/Fnlib*
BUILDLINK_FILES.fnlib+=	lib/libFnlib.*

.include "../../graphics/imlib/buildlink.mk"

BUILDLINK_TARGETS.fnlib=	fnlib-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.fnlib}

pre-configure: ${BUILDLINK_TARGETS.fnlib}
fnlib-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# FNLIB_BUILDLINK_MK
