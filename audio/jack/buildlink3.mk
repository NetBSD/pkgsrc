# $NetBSD: buildlink3.mk,v 1.20 2025/02/12 06:44:23 ryoon Exp $

BUILDLINK_TREE+=	jack

.if !defined(JACK_BUILDLINK3_MK)
JACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jack+=	jack>=1.9.19
BUILDLINK_ABI_DEPENDS.jack?=	jack>=1.9.21nb4
BUILDLINK_PKGSRCDIR.jack?=	../../audio/jack

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif # JACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-jack
