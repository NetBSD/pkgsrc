# $NetBSD: buildlink3.mk,v 1.1 2021/05/16 10:14:09 nia Exp $

BUILDLINK_TREE+=	fftw-quad

.if !defined(FFTW_QUAD_BUILDLINK3_MK)
FFTW_QUAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftw-quad+=	fftw-quad>=3.3.9
BUILDLINK_PKGSRCDIR.fftw-quad?=		../../math/fftw-quad

.include "../../math/fftw/buildlink3.mk"
.endif	# FFTW_QUAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftw-quad
