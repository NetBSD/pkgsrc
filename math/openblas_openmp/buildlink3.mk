# $NetBSD: buildlink3.mk,v 1.2 2020/11/05 17:06:10 bacon Exp $

BUILDLINK_TREE+=	openblas_openmp

.if !defined(OPENBLAS_OPENMP_BUILDLINK3_MK)
OPENBLAS_OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas_openmp+=	openblas_openmp>=0.3.5
BUILDLINK_PKGSRCDIR.openblas_openmp?=	../../math/openblas_openmp
.endif	# OPENBLAS_OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas_openmp
