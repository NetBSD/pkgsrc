# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:56 joerg Exp $

BUILDLINK_TREE+=	fftwf

.if !defined(FFTWF_BUILDLINK3_MK)
FFTWF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftwf+=	fftwf>=3.0
BUILDLINK_ABI_DEPENDS.fftwf+=	fftwf>=3.0.1nb1
BUILDLINK_PKGSRCDIR.fftwf?=	../../math/fftwf

.include "../../math/fftw/buildlink3.mk"
.endif # FFTWF_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftwf
