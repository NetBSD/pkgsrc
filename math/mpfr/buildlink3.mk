# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:46 dholland Exp $

BUILDLINK_TREE+=	mpfr

.if !defined(MPFR_BUILDLINK3_MK)
MPFR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.0.3
BUILDLINK_ABI_DEPENDS.mpfr+=	mpfr>=3.0.0.3
BUILDLINK_PKGSRCDIR.mpfr?=	../../math/mpfr

.include "../../devel/gmp/buildlink3.mk"
.endif # MPFR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpfr
