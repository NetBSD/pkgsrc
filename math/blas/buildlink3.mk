# $NetBSD: buildlink3.mk,v 1.1 2004/02/26 15:26:05 adam Exp $
#
# This Makefile fragment is included by packages that use blas.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BLAS_BUILDLINK3_MK:=	${BLAS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	blas
.endif

.if !empty(BLAS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			blas
BUILDLINK_DEPENDS.blas+=		blas>=1.0nb2
BUILDLINK_PKGSRCDIR.blas?=		../../math/blas

.endif # BLAS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
