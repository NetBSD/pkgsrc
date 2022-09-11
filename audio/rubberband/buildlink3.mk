# $NetBSD: buildlink3.mk,v 1.4 2022/09/11 12:51:04 wiz Exp $

BUILDLINK_TREE+=	rubberband

.if !defined(RUBBERBAND_BUILDLINK3_MK)
RUBBERBAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rubberband+=	rubberband>=1.8.1
BUILDLINK_ABI_DEPENDS.rubberband?=	rubberband>=1.9.2nb2
BUILDLINK_PKGSRCDIR.rubberband?=	../../audio/rubberband

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.endif	# RUBBERBAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-rubberband
