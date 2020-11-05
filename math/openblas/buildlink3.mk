# $NetBSD: buildlink3.mk,v 1.1 2020/11/05 16:31:45 bacon Exp $

BUILDLINK_TREE+=	openblas

.if !defined(OPENBLAS_BUILDLINK3_MK)
OPENBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas+=	openblas>=0.3.5
BUILDLINK_PKGSRCDIR.openblas?=		../../math/openblas
.endif	# OPENBLAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas
