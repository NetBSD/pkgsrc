# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:06 jlam Exp $
#
# This Makefile fragment is included by packages that use pth.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pth to the dependency pattern
#     for the version of pth desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(PTH_BUILDLINK2_MK)
PTH_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.pth?=	pth>=1.3.2
DEPENDS+=		${BUILDLINK_DEPENDS.pth}:../../devel/pth

BUILDLINK_PREFIX.pth=	${LOCALBASE}
BUILDLINK_FILES.pth=	include/pth.h
BUILDLINK_FILES.pth+=	include/pthread.h
BUILDLINK_FILES.pth+=	lib/libpth.*
BUILDLINK_FILES.pth+=	lib/libpthread.*

BUILDLINK_TARGETS+=	pth-buildlink

pth-buildlink: _BUILDLINK_USE

.endif	# PTH_BUILDLINK2_MK
