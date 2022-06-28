# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:34:37 wiz Exp $

BUILDLINK_TREE+=	openblas

.if !defined(OPENBLAS_BUILDLINK3_MK)
OPENBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas+=	openblas>=0.3.5
BUILDLINK_ABI_DEPENDS.openblas?=	openblas>=0.3.15nb2
BUILDLINK_PKGSRCDIR.openblas?=		../../math/openblas
.endif	# OPENBLAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas
