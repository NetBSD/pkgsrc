# $NetBSD: buildlink.mk,v 1.3 2001/06/11 01:59:34 jlam Exp $
#
# This Makefile fragment is included by packages that use gdbm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define GDBM_REQD to the version of gdbm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GDBM_BUILDLINK_MK)
GDBM_BUILDLINK_MK=	# defined

GDBM_REQD?=		1.7.3
DEPENDS+=		gdbm>=${GDBM_REQD}:../../databases/gdbm

BUILDLINK_PREFIX.gdbm=		${LOCALBASE}
BUILDLINK_FILES.gdbm=		include/gdbm.h
BUILDLINK_FILES.gdbm+=		lib/libgdbm.*

BUILDLINK_TARGETS.gdbm=		gdbm-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gdbm}

pre-configure: ${BUILDLINK_TARGETS.gdbm}
gdbm-buildlink: _BUILDLINK_USE

.endif	# GDBM_BUILDLINK_MK
