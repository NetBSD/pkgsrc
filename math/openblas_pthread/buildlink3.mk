# $NetBSD: buildlink3.mk,v 1.2 2020/11/05 17:06:10 bacon Exp $

BUILDLINK_TREE+=	openblas_pthread

.if !defined(OPENBLAS_PTHREAD_BUILDLINK3_MK)
OPENBLAS_PTHREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas_pthread+=	openblas_pthread>=0.3.5
BUILDLINK_PKGSRCDIR.openblas_pthread?=		../../math/openblas_pthread
.endif	# OPENBLAS_PTHREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas_pthread
