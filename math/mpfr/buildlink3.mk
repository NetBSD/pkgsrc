# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	mpfr

.if !defined(MPFR_BUILDLINK3_MK)
MPFR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.0.3
BUILDLINK_PKGSRCDIR.mpfr?=	../../math/mpfr

.include "../../devel/gmp/buildlink3.mk"
.endif # MPFR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpfr
