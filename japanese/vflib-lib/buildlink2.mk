# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:43 jlam Exp $
#
# This Makefile fragment is included by packages that use VFlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.vflib to the dependency pattern
#     for the version of VFlib desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(VFLIB_BUILDLINK2_MK)
VFLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.vflib?=	ja-vflib-lib>=2.24.2
DEPENDS+=	${BUILDLINK_DEPENDS.vflib}:../../japanese/vflib-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.vflib=ja-vflib-lib
BUILDLINK_PREFIX.vflib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.vflib=		include/VF.h
BUILDLINK_FILES.vflib+=		lib/libVFlib2.*

.include "../../graphics/freetype-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	vflib-buildlink

vflib-buildlink: _BUILDLINK_USE

.endif	# VFLIB_BUILDLINK2_MK
