# $NetBSD: buildlink3.mk,v 1.5 2026/09/29 06:03:39 wiz Exp $

BUILDLINK_TREE+=	SDL3_mixer

.if !defined(SDL3_MIXER_BUILDLINK3_MK)
SDL3_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL3_mixer+=	SDL3_mixer>=3.2.0
BUILDLINK_ABI_DEPENDS.SDL3_mixer?=	SDL3_mixer>=3.2.4nb4
BUILDLINK_PKGSRCDIR.SDL3_mixer?=	../../audio/SDL3_mixer

.include "../../devel/SDL3/buildlink3.mk"
.endif	# SDL3_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL3_mixer
