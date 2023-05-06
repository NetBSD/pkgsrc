# $NetBSD: buildlink3.mk,v 1.5 2023/05/06 19:08:45 ryoon Exp $

BUILDLINK_TREE+=	aubio

.if !defined(AUBIO_BUILDLINK3_MK)
AUBIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aubio+=	aubio>=0.3.2
BUILDLINK_ABI_DEPENDS.aubio?=	aubio>=0.4.9nb11
BUILDLINK_PKGSRCDIR.aubio?=	../../audio/aubio

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.endif	# AUBIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-aubio
