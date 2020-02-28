# $NetBSD: buildlink3.mk,v 1.9 2020/02/28 21:48:53 plunky Exp $

BUILDLINK_TREE+=	blas

.if !defined(BLAS_BUILDLINK3_MK)
BLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blas+=	blas>=1.0nb2
BUILDLINK_ABI_DEPENDS.blas+=	blas>=1.0nb3
BUILDLINK_PKGSRCDIR.blas?=	../../math/blas

BLAS_LIBS=			-lblas
.endif # BLAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-blas
