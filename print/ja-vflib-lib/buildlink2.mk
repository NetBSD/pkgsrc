# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:42 jlam Exp $

.if !defined(VFLIB_BUILDLINK2_MK)
VFLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		vflib
BUILDLINK_PKGBASE.vflib?=	ja-vflib-lib
BUILDLINK_DEPENDS.vflib?=	ja-vflib-lib>=2.24.2
BUILDLINK_PKGSRCDIR.vflib?=	../../print/ja-vflib-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.vflib=ja-vflib-lib
BUILDLINK_PREFIX.vflib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.vflib=		include/VF.h
BUILDLINK_FILES.vflib+=		lib/libVFlib2.*

.include "../../graphics/freetype-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	vflib-buildlink

vflib-buildlink: _BUILDLINK_USE

.endif	# VFLIB_BUILDLINK2_MK
