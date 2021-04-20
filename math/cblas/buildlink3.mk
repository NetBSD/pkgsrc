# $NetBSD: buildlink3.mk,v 1.1 2021/04/20 20:37:03 thor Exp $

BUILDLINK_TREE+=	cblas

.if !defined(CBLAS_BUILDLINK3_MK)
CBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas+=	cblas>=3.9.0
BUILDLINK_PKGSRCDIR.cblas?=	../../math/cblas

.include	"../../mk/blas.buildlink3.mk"
.endif


BUILDLINK_TREE+=	-cblas
