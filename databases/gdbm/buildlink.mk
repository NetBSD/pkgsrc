# $NetBSD: buildlink.mk,v 1.5 2001/06/23 19:26:51 jlam Exp $
#
# This Makefile fragment is included by packages that use gdbm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gdbm to the dependency pattern
#     for the version of gdbm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GDBM_BUILDLINK_MK)
GDBM_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.gdbm?=	gdbm>=1.7.3
DEPENDS+=	${BUILDLINK_DEPENDS.gdbm}:../../databases/gdbm

BUILDLINK_PREFIX.gdbm=	${LOCALBASE}
BUILDLINK_FILES.gdbm=	include/gdbm.h
BUILDLINK_FILES.gdbm+=	lib/libgdbm.*

BUILDLINK_TARGETS.gdbm=	gdbm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gdbm}

pre-configure: ${BUILDLINK_TARGETS.gdbm}
gdbm-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# GDBM_BUILDLINK_MK
