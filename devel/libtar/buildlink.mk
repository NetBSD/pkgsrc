# $NetBSD: buildlink.mk,v 1.1.1.1 2002/04/22 17:14:48 seb Exp $
#
# This Makefile fragment is included by packages that use libtar. 
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libtar to the dependency pattern
#     for the version of libtar desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBTAR_BUILDLINK_MK)
LIBTAR_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libtar?=	libtar>=1.2.5

DEPENDS+=		${BUILDLINK_DEPENDS.libtar}:../../devel/libtar
EVAL_PREFIX+=		BUILDLINK_PREFIX.libtar=libtar
BUILDLINK_PREFIX.libtar_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libtar=		include/libtar*
BUILDLINK_FILES.libtar+=	lib/libtar.*

BUILDLINK_TARGETS.libtar=	libtar-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libtar}

pre-configure: ${BUILDLINK_TARGETS.libtar}
libtar-buildlink: _BUILDLINK_USE

.endif	# LIBTAR_BUILDLINK_MK
