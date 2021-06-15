# $NetBSD: buildlink3.mk,v 1.2 2021/06/15 04:41:52 thor Exp $

BUILDLINK_TREE+=	lapacke

.if !defined(LAPACKE_BUILDLINK3_MK)
LAPACKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapacke+=	lapacke>=3.9.0
BUILDLINK_ABI_DEPENDS.lapacke?=	lapacke>=3.9.1nb2
BUILDLINK_PKGSRCDIR.lapacke?=	../../math/lapacke

.include	"../../math/lapack/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-lapacke
