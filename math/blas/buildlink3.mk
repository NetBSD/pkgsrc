# $NetBSD: buildlink3.mk,v 1.10 2020/10/12 21:51:57 bacon Exp $

BUILDLINK_TREE+=	blas

.if !defined(BLAS_BUILDLINK3_MK)
BLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blas+=	blas>=3.9.0
BUILDLINK_ABI_DEPENDS.blas+=	blas>=3.9.0nb1
BUILDLINK_PKGSRCDIR.blas?=	../../math/blas
.endif # BLAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-blas
