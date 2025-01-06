# $NetBSD: buildlink3.mk,v 1.20 2025/01/06 21:49:01 ktnb Exp $

BUILDLINK_TREE+=	SDL_mixer

.if !defined(SDL_MIXER_BUILDLINK3_MK)
SDL_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb2
BUILDLINK_ABI_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.12nb8
BUILDLINK_PKGSRCDIR.SDL_mixer?=		../../audio/SDL_mixer
BUILDLINK_INCDIRS.SDL_mixer?=		include/SDL

.include "../../devel/SDL/buildlink3.mk"
.endif # SDL_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_mixer
