# $NetBSD: buildlink.mk,v 1.8 2001/07/27 13:33:22 jlam Exp $
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

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gdbm?=	gdbm>=1.7.3
DEPENDS+=	${BUILDLINK_DEPENDS.gdbm}:../../databases/gdbm

EVAL_PREFIX+=		BUILDLINK_PREFIX.gdbm=gdbm
BUILDLINK_PREFIX.gdbm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gdbm=	include/gdbm.h
BUILDLINK_FILES.gdbm+=	lib/libgdbm.*

BUILDLINK_TARGETS.gdbm=	gdbm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gdbm}

pre-configure: ${BUILDLINK_TARGETS.gdbm}
gdbm-buildlink: _BUILDLINK_USE

.endif	# GDBM_BUILDLINK_MK
