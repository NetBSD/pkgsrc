# $NetBSD: buildlink3.mk,v 1.1 2024/05/06 18:01:31 nia Exp $

BUILDLINK_TREE+=	SDL2_mixer

.if !defined(SDL2_MIXER_BUILDLINK3_MK)
SDL2_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.0
BUILDLINK_ABI_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.0
BUILDLINK_PKGSRCDIR.SDL2_mixer?=	../../audio/SDL2_mixer-legacy

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_mixer
