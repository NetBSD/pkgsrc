# $NetBSD: buildlink3.mk,v 1.18 2023/05/06 19:08:46 ryoon Exp $

BUILDLINK_TREE+=	jack

.if !defined(JACK_BUILDLINK3_MK)
JACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jack+=	jack>=1.9.19
BUILDLINK_ABI_DEPENDS.jack?=	jack>=1.9.21nb2
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
