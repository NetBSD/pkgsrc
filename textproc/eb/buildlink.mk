# $NetBSD: buildlink.mk,v 1.2 2002/03/22 03:57:54 uebayasi Exp $
#
# This Makefile fragment is included by packages that use EB.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.eb to the dependency pattern
#     for the version of eb desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(EB_BUILDLINK_MK)
EB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

# 3.2.0 had an 'appendix' bug, so bump the base version.
BUILDLINK_DEPENDS.eb?=	eb>=3.2.1
DEPENDS+=	${BUILDLINK_DEPENDS.eb}:../../textproc/eb

EVAL_PREFIX+=		BUILDLINK_PREFIX.eb=eb
#BUILDLINK_PREFIX.png_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.eb=	include/eb/*.h
BUILDLINK_FILES.eb+=	lib/libeb.*

BUILDLINK_TARGETS.eb=	eb-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.eb}

.include "../../mk/bsd.prefs.mk"

pre-configure: ${BUILDLINK_TARGETS.eb}
eb-buildlink: _BUILDLINK_USE

.endif	# EB_BUILDLINK_MK
