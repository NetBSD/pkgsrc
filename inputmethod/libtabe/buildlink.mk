# $NetBSD: buildlink.mk,v 1.2.2.2 2002/06/23 18:47:54 jlam Exp $
#
# This Makefile fragment is included by packages that use libtabe.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libtabe to the dependency pattern
#     for the version of libtabe desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBTABE_BUILDLINK_MK)
LIBTABE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libtabe?=	libtabe>=0.2.5
DEPENDS+=	${BUILDLINK_DEPENDS.libtabe}:../../inputmethod/libtabe

EVAL_PREFIX+=			BUILDLINK_PREFIX.libtabe=libtabe
BUILDLINK_PREFIX.libtabe_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libtabe=		include/bims.h
BUILDLINK_FILES.libtabe+=		include/tabe.h
BUILDLINK_FILES.libtabe+=		lib/libbims.*
BUILDLINK_FILES.libtabe+=		lib/libtabe.*

BUILDLINK_TARGETS.libtabe=	libtabe-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libtabe}

pre-configure: ${BUILDLINK_TARGETS.libtabe}
libtabe-buildlink: _BUILDLINK_USE

.endif	# LIBTABE_BUILDLINK_MK
