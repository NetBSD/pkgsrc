# $NetBSD: buildlink3.mk,v 1.17 2025/02/12 06:44:17 ryoon Exp $

BUILDLINK_TREE+=	SDL2_mixer

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
# This defines SDL2_MIXER_BUILDLINK3_MK.
.  include "../../audio/SDL2_mixer-legacy/buildlink3.mk"
.endif

.if !defined(SDL2_MIXER_BUILDLINK3_MK)
SDL2_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.0
BUILDLINK_ABI_DEPENDS.SDL2_mixer?=	SDL2_mixer>=2.8.0nb1
BUILDLINK_PKGSRCDIR.SDL2_mixer?=	../../audio/SDL2_mixer

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_mixer
