# $NetBSD: buildlink.mk,v 1.4 2002/08/31 16:54:33 wiz Exp $
#
# This Makefile fragment is included by packages that use uulib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.uulib to the dependency pattern
#     for the version of uulib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(UULIB_BUILDLINK_MK)
UULIB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.uulib?=	uulib>=0.5.18
DEPENDS+=	${BUILDLINK_DEPENDS.uulib}:../../converters/uulib

EVAL_PREFIX+=		BUILDLINK_PREFIX.uulib=uulib
BUILDLINK_PREFIX.uulib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.uulib=	include/uu.h
BUILDLINK_FILES.uulib+=	lib/libuu.*

BUILDLINK_TARGETS.uulib=	uulib-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.uulib}

pre-configure: ${BUILDLINK_TARGETS.uulib}
uulib-buildlink: _BUILDLINK_USE

.endif	# UULIB_BUILDLINK_MK
