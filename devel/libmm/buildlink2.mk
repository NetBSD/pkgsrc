# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/21 23:00:21 jlam Exp $

.if !defined(LIBMM_BUILDLINK2_MK)
LIBMM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libmm
BUILDLINK_DEPENDS.libmm?=	libmm>=1.1.3
BUILDLINK_PKGSRCDIR.libmm?=	../../devel/libmm

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmm=libmm
BUILDLINK_PREFIX.libmm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmm=		include/mm.h
BUILDLINK_FILES.libmm+=		lib/libmm.*

BUILDLINK_TARGETS+=	libmm-buildlink

libmm-buildlink: _BUILDLINK_USE

.endif	# LIBMM_BUILDLINK2_MK
