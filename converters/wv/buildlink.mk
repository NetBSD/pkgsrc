# $NetBSD: buildlink.mk,v 1.3 2002/09/10 16:06:37 wiz Exp $
#
# This Makefile fragment is included by packages that use wv.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.wv to the dependency pattern
#     for the version of wv desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(WV_BUILDLINK_MK)
WV_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.wv?=	wv>=0.7.0nb2
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.wv}:../../converters/wv

EVAL_PREFIX+=			BUILDLINK_PREFIX.wv=wv
BUILDLINK_PREFIX.wv_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.wv=	include/wv.h
BUILDLINK_FILES.wv+=	lib/libwv.*

BUILDLINK_TARGETS.wv=	wv-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.wv}

pre-configure: ${BUILDLINK_TARGETS.wv}
wv-buildlink: _BUILDLINK_USE

.endif	# WV_BUILDLINK_MK
