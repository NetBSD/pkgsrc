# $NetBSD: buildlink.mk,v 1.1 2001/10/19 21:31:09 jlam Exp $
#
# This Makefile fragment is included by packages that use sane.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.sane to the dependency pattern
#     for the version of sane desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SANE_BUILDLINK_MK)
SANE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.sane?=	sane-backends>=1.0.3
DEPENDS+=	${BUILDLINK_DEPENDS.sane}:../../graphics/sane-backends

EVAL_PREFIX+=			BUILDLINK_PREFIX.sane=sane-backends
BUILDLINK_PREFIX.sane_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sane=		include/sane/*.h
BUILDLINK_FILES.sane+=		lib/libsane.*

.include "../../devel/libusb/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"

BUILDLINK_TARGETS.sane=	sane-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.sane}

pre-configure: ${BUILDLINK_TARGETS.sane}
sane-buildlink: _BUILDLINK_USE

.endif	# SANE_BUILDLINK_MK
