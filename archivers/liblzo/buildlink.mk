# $NetBSD: buildlink.mk,v 1.2 2001/07/01 22:59:08 jlam Exp $
#
# This Makefile fragment is included by packages that use liblzo.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.liblzo to the dependency pattern
#     for the version of liblzo desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(liblzo_BUILDLINK_MK)
liblzo_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.liblzo?=	liblzo>=1.04
DEPENDS+=	${BUILDLINK_DEPENDS.liblzo}:../../archivers/liblzo

BUILDLINK_PREFIX.liblzo=	${LOCALBASE}
BUILDLINK_FILES.liblzo=		include/liblzo.h
BUILDLINK_FILES.liblzo+=	lib/libliblzo.*

BUILDLINK_TARGETS.liblzo=	liblzo-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.liblzo}

pre-configure: ${BUILDLINK_TARGETS.liblzo}
liblzo-buildlink: _BUILDLINK_USE

.endif	# liblzo_BUILDLINK_MK
