# $NetBSD: buildlink3.mk,v 1.2 2011/09/14 17:14:09 hans Exp $

BUILDLINK_TREE+=	mpcomplex

.if !defined(MPCOMPLEX_BUILDLINK3_MK)
MPCOMPLEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpcomplex+=	mpcomplex>=0.8.2
BUILDLINK_PKGSRCDIR.mpcomplex?=	../../math/mpcomplex

BUILDLINK_API_DEPENDS.gmp+=     gmp>=4.3.2
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=    mpfr>=2.4.2
.include "../../math/mpfr/buildlink3.mk"
.endif	# MPCOMPLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpcomplex
