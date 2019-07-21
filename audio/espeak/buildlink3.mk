# $NetBSD: buildlink3.mk,v 1.3 2019/07/21 22:47:56 nia Exp $

BUILDLINK_TREE+=	espeak

.if !defined(ESPEAK_BUILDLINK3_MK)
ESPEAK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.espeak+=	espeak>=1.26
BUILDLINK_PKGSRCDIR.espeak?=	../../audio/espeak

.include "../../audio/portaudio-devel/buildlink3.mk"
.endif # ESPEAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-espeak
