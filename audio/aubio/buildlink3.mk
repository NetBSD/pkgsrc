# $NetBSD: buildlink3.mk,v 1.4 2022/09/11 12:51:03 wiz Exp $

BUILDLINK_TREE+=	aubio

.if !defined(AUBIO_BUILDLINK3_MK)
AUBIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aubio+=	aubio>=0.3.2
BUILDLINK_ABI_DEPENDS.aubio?=	aubio>=0.4.9nb7
BUILDLINK_PKGSRCDIR.aubio?=	../../audio/aubio

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.endif	# AUBIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-aubio
