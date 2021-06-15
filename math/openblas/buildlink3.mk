# $NetBSD: buildlink3.mk,v 1.2 2021/06/15 04:41:52 thor Exp $

BUILDLINK_TREE+=	openblas

.if !defined(OPENBLAS_BUILDLINK3_MK)
OPENBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas+=	openblas>=0.3.5
BUILDLINK_ABI_DEPENDS.openblas?=	openblas>=0.3.15nb1
BUILDLINK_PKGSRCDIR.openblas?=		../../math/openblas
.endif	# OPENBLAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas
