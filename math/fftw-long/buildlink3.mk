# $NetBSD: buildlink3.mk,v 1.1 2021/05/16 10:14:09 nia Exp $

BUILDLINK_TREE+=	fftw-long

.if !defined(FFTW_LONG_BUILDLINK3_MK)
FFTW_LONG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftw-long+=	fftw-long>=3.3.9
BUILDLINK_PKGSRCDIR.fftw-long?=		../../math/fftw-long

.include "../../math/fftw/buildlink3.mk"
.endif	# FFTW_LONG_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftw-long
