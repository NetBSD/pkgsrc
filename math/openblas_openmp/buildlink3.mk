# $NetBSD: buildlink3.mk,v 1.3 2021/06/15 04:41:53 thor Exp $

BUILDLINK_TREE+=	openblas_openmp

.if !defined(OPENBLAS_OPENMP_BUILDLINK3_MK)
OPENBLAS_OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas_openmp+=	openblas_openmp>=0.3.5
BUILDLINK_ABI_DEPENDS.openblas_openmp?=	openblas_openmp>=0.3.15nb1
BUILDLINK_PKGSRCDIR.openblas_openmp?=	../../math/openblas_openmp
.endif	# OPENBLAS_OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas_openmp
