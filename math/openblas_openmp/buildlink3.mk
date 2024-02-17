# $NetBSD: buildlink3.mk,v 1.4 2024/02/17 10:13:20 adam Exp $

BUILDLINK_TREE+=	openblas_openmp

.if !defined(OPENBLAS_OPENMP_BUILDLINK3_MK)
OPENBLAS_OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas_openmp+=	openblas_openmp>=0.3.5
BUILDLINK_ABI_DEPENDS.openblas_openmp+=	openblas_openmp>=0.3.15nb1
BUILDLINK_PKGSRCDIR.openblas_openmp?=	../../math/openblas_openmp
.endif	# OPENBLAS_OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas_openmp
