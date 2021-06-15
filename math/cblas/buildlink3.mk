# $NetBSD: buildlink3.mk,v 1.2 2021/06/15 04:41:52 thor Exp $

BUILDLINK_TREE+=	cblas

.if !defined(CBLAS_BUILDLINK3_MK)
CBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas+=	cblas>=3.9.0
BUILDLINK_ABI_DEPENDS.cblas?=	cblas>=3.9.1nb1
BUILDLINK_PKGSRCDIR.cblas?=	../../math/cblas

.include	"../../math/blas/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-cblas
