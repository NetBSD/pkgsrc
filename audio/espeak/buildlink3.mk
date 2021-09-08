# $NetBSD: buildlink3.mk,v 1.6 2021/09/08 21:04:54 nia Exp $

BUILDLINK_TREE+=	espeak

.if !defined(ESPEAK_BUILDLINK3_MK)
ESPEAK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.espeak+=	espeak>=1.26
BUILDLINK_ABI_DEPENDS.espeak?=	espeak>=1.48.04nb2
BUILDLINK_PKGSRCDIR.espeak?=	../../audio/espeak

.include "../../audio/portaudio/buildlink3.mk"
.endif # ESPEAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-espeak
