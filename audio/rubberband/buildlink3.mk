# $NetBSD: buildlink3.mk,v 1.1 2015/12/28 03:29:33 kamil Exp $

BUILDLINK_TREE+=	rubberband

.if !defined(RUBBERBAND_BUILDLINK3_MK)
RUBBERBAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rubberband+=	rubberband>=1.8.1
BUILDLINK_PKGSRCDIR.rubberband?=	../../audio/rubberband

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.endif	# RUBBERBAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-rubberband
