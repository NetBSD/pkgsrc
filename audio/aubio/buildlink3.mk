# $NetBSD: buildlink3.mk,v 1.2 2020/08/18 17:57:24 leot Exp $

BUILDLINK_TREE+=	aubio

.if !defined(AUBIO_BUILDLINK3_MK)
AUBIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aubio+=	aubio>=0.3.2
BUILDLINK_ABI_DEPENDS.aubio?=	aubio>=0.4.9nb3
BUILDLINK_PKGSRCDIR.aubio?=	../../audio/aubio

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.endif	# AUBIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-aubio
