# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:00 jlam Exp $
#
# This Makefile fragment is included by packages that use gdbm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gdbm to the dependency pattern
#     for the version of gdbm desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(GDBM_BUILDLINK2_MK)
GDBM_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.gdbm?=	gdbm>=1.7.3
DEPENDS+=	${BUILDLINK_DEPENDS.gdbm}:../../databases/gdbm

BUILDLINK_PREFIX.gdbm=	${LOCALBASE}
BUILDLINK_FILES.gdbm=	include/gdbm.h
BUILDLINK_FILES.gdbm+=	lib/libgdbm.*

BUILDLINK_TARGETS+=	gdbm-buildlink

gdbm-buildlink: _BUILDLINK_USE

.endif	# GDBM_BUILDLINK2_MK
