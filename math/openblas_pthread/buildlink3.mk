# $NetBSD: buildlink3.mk,v 1.3 2021/06/15 04:41:53 thor Exp $

BUILDLINK_TREE+=	openblas_pthread

.if !defined(OPENBLAS_PTHREAD_BUILDLINK3_MK)
OPENBLAS_PTHREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas_pthread+=	openblas_pthread>=0.3.5
BUILDLINK_ABI_DEPENDS.openblas_pthread?=	openblas_pthread>=0.3.15nb1
BUILDLINK_PKGSRCDIR.openblas_pthread?=		../../math/openblas_pthread
.endif	# OPENBLAS_PTHREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas_pthread
