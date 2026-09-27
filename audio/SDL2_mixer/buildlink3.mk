# $NetBSD: buildlink3.mk,v 1.22 2026/09/27 11:34:47 tnn Exp $

BUILDLINK_TREE+=	SDL2_mixer

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
# This defines SDL2_MIXER_BUILDLINK3_MK.
.  include "../../audio/SDL2_mixer-legacy/buildlink3.mk"
.endif

.if !defined(SDL2_MIXER_BUILDLINK3_MK)
SDL2_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.0
BUILDLINK_ABI_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.8.2nb3
BUILDLINK_PKGSRCDIR.SDL2_mixer?=	../../audio/SDL2_mixer

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_mixer
