# $NetBSD: buildlink3.mk,v 1.22 2026/07/13 04:35:17 wiz Exp $

BUILDLINK_TREE+=	jack

.if !defined(JACK_BUILDLINK3_MK)
JACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jack+=	jack>=1.9.19
BUILDLINK_ABI_DEPENDS.jack?=	jack>=1.9.22nb1
BUILDLINK_PKGSRCDIR.jack?=	../../audio/jack

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.endif # JACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-jack
