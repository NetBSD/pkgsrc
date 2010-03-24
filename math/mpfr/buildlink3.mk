# $NetBSD: buildlink3.mk,v 1.8 2010/03/24 21:54:16 asau Exp $

BUILDLINK_TREE+=	mpfr

.if !defined(MPFR_BUILDLINK3_MK)
MPFR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.0.3
BUILDLINK_ABI_DEPENDS.mpfr?=	mpfr>=2.4.2.3nb1
BUILDLINK_PKGSRCDIR.mpfr?=	../../math/mpfr

.include "../../devel/gmp/buildlink3.mk"
.endif # MPFR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpfr
