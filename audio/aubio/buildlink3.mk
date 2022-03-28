# $NetBSD: buildlink3.mk,v 1.3 2022/03/28 10:43:30 tnn Exp $

BUILDLINK_TREE+=	aubio

.if !defined(AUBIO_BUILDLINK3_MK)
AUBIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aubio+=	aubio>=0.3.2
BUILDLINK_ABI_DEPENDS.aubio?=	aubio>=0.4.9nb6
BUILDLINK_PKGSRCDIR.aubio?=	../../audio/aubio

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.endif	# AUBIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-aubio
