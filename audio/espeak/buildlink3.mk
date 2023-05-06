# $NetBSD: buildlink3.mk,v 1.9 2023/05/06 19:08:45 ryoon Exp $

BUILDLINK_TREE+=	espeak

.if !defined(ESPEAK_BUILDLINK3_MK)
ESPEAK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.espeak+=	espeak>=1.26
BUILDLINK_ABI_DEPENDS.espeak?=	espeak>=1.48.04nb5
BUILDLINK_PKGSRCDIR.espeak?=	../../audio/espeak

.include "../../audio/portaudio/buildlink3.mk"
.endif # ESPEAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-espeak
