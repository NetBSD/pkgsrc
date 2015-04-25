# $NetBSD: buildlink3.mk,v 1.4 2015/04/25 14:20:17 tnn Exp $

BUILDLINK_TREE+=	SDL2_mixer

.if !defined(SDL2_MIXER_BUILDLINK3_MK)
SDL2_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.0
BUILDLINK_ABI_DEPENDS.SDL2_mixer?=	SDL2_mixer>=2.0.0nb2
BUILDLINK_PKGSRCDIR.SDL2_mixer?=	../../audio/SDL2_mixer

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_mixer
