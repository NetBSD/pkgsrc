# $NetBSD: buildlink2.mk,v 1.1 2002/09/29 03:22:24 jlam Exp $

.if !defined(LIBFFM_BUILDLINK2_MK)
LIBFFM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libffm
BUILDLINK_DEPENDS.libffm?=	libffm>=0.28
BUILDLINK_PKGSRCDIR.libffm?=	../../math/libffm
BUILDLINK_DEPMETHOD.libffm?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.libffm=libffm
BUILDLINK_PREFIX.libffm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libffm+=	include/libffm.h
BUILDLINK_FILES.libffm+=	lib/libffm.*

BUILDLINK_TARGETS+=	libffm-buildlink

libffm-buildlink: _BUILDLINK_USE

.endif	# LIBFFM_BUILDLINK2_MK
