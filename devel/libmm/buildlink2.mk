# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/08/22 21:04:22 jlam Exp $

.if !defined(LIBMM_BUILDLINK2_MK)
LIBMM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libmm
BUILDLINK_DEPENDS.libmm?=	libmm>=1.2.1
BUILDLINK_PKGSRCDIR.libmm?=	../../devel/libmm

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmm=libmm
BUILDLINK_PREFIX.libmm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmm=		include/mm.h
BUILDLINK_FILES.libmm+=		lib/libmm.*

BUILDLINK_TARGETS+=	libmm-buildlink

libmm-buildlink: _BUILDLINK_USE

.endif	# LIBMM_BUILDLINK2_MK
