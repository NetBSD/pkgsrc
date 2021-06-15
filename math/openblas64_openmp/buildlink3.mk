# $NetBSD: buildlink3.mk,v 1.1 2021/06/15 04:41:53 thor Exp $

BUILDLINK_TREE+=	openblas64_openmp

.if !defined(OPENBLAS64_OPENMP_BUILDLINK3_MK)
OPENBLAS64_OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas64_openmp+=	openblas64_openmp>=0.3.5
BUILDLINK_PKGSRCDIR.openblas64_openmp?=		../../math/openblas64_openmp
.endif	# OPENBLAS64_OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas64_openmp
