# $NetBSD: buildlink2.mk,v 1.5 2003/12/04 09:13:58 adam Exp $

.if !defined(BLAS_BUILDLINK2_MK)
BLAS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		blas
BUILDLINK_DEPENDS.blas?=	blas>=1.0
BUILDLINK_PKGSRCDIR.blas?=	../../math/blas

EVAL_PREFIX+=			BUILDLINK_PREFIX.blas=blas
BUILDLINK_PREFIX.blas_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.blas=		lib/libblas*

BUILDLINK_TARGETS+=		blas-buildlink

blas-buildlink: _BUILDLINK_USE

.endif	# BLAS_BUILDLINK2_MK
