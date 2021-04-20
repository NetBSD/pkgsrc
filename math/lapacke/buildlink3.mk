# $NetBSD: buildlink3.mk,v 1.1 2021/04/20 20:40:47 thor Exp $

BUILDLINK_TREE+=	lapacke

.if !defined(LAPACKE_BUILDLINK3_MK)
LAPACKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapacke+=	lapacke>=3.9.0
BUILDLINK_PKGSRCDIR.lapacke?=	../../math/lapacke

.include	"../../mk/blas.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-lapacke
