# $NetBSD: buildlink3.mk,v 1.3 2015/04/03 18:12:59 bsiegert Exp $

BUILDLINK_TREE+=	SDL2_mixer

.if !defined(SDL2_MIXER_BUILDLINK3_MK)
SDL2_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.0
BUILDLINK_ABI_DEPENDS.SDL2_mixer?=	SDL2_mixer>=2.0.0nb1
BUILDLINK_PKGSRCDIR.SDL2_mixer?=	../../audio/SDL2_mixer

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_mixer
