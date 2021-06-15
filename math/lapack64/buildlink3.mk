# $NetBSD: buildlink3.mk,v 1.1 2021/06/15 04:41:52 thor Exp $

BUILDLINK_TREE+=	lapack64

.if !defined(LAPACK64_BUILDLINK3_MK)
LAPACK64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapack64+=	lapack64>=3.9.0
BUILDLINK_ABI_DEPENDS.lapack64+=	lapack64>=3.9.0
BUILDLINK_PKGSRCDIR.lapack64?=		../../math/lapack64

.include "../../math/blas64/buildlink3.mk"

.endif # LAPACK64_BUILDLINK3_MK

BUILDLINK_TREE+=	-lapack64
