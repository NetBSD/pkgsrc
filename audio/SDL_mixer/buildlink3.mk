# $NetBSD: buildlink3.mk,v 1.10 2005/12/11 09:40:37 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_MIXER_BUILDLINK3_MK:=	${SDL_MIXER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_mixer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_mixer}
BUILDLINK_PACKAGES+=	SDL_mixer

.if !empty(SDL_MIXER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb2
BUILDLINK_RECOMMENDED.SDL_mixer+=	SDL_mixer>=1.2.6nb3
BUILDLINK_PKGSRCDIR.SDL_mixer?=	../../audio/SDL_mixer
BUILDLINK_INCDIRS.SDL_mixer?=	include/SDL
.endif	# SDL_MIXER_BUILDLINK3_MK

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
