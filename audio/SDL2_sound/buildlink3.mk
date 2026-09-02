# $NetBSD: buildlink3.mk,v 1.9 2026/09/02 19:00:43 wiz Exp $

BUILDLINK_TREE+=	SDL2_sound

.if !defined(SDL2_SOUND_BUILDLINK3_MK)
SDL2_SOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_sound+=	SDL2_sound>=2.0.1
BUILDLINK_ABI_DEPENDS.SDL2_sound+=	SDL2_sound>=2.0.4nb4
BUILDLINK_PKGSRCDIR.SDL2_sound?=	../../audio/SDL2_sound

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_SOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_sound
