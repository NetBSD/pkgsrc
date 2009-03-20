# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:56 joerg Exp $

BUILDLINK_TREE+=	blas

.if !defined(BLAS_BUILDLINK3_MK)
BLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blas+=	blas>=1.0nb2
BUILDLINK_ABI_DEPENDS.blas+=	blas>=1.0nb3
BUILDLINK_PKGSRCDIR.blas?=	../../math/blas
.endif # BLAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-blas
