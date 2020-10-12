# $NetBSD: buildlink3.mk,v 1.10 2020/10/12 21:51:57 bacon Exp $

BUILDLINK_TREE+=	lapack

.if !defined(LAPACK_BUILDLINK3_MK)
LAPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapack+=	lapack>=3.9.0
BUILDLINK_ABI_DEPENDS.lapack+=	lapack>=3.9.0nb1
BUILDLINK_PKGSRCDIR.lapack?=	../../math/lapack

.include "../../math/blas/buildlink3.mk"

.endif # LAPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lapack
