# $NetBSD: buildlink3.mk,v 1.15 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_MIXER_BUILDLINK3_MK:=	${SDL_MIXER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_mixer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_mixer}
BUILDLINK_PACKAGES+=	SDL_mixer
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}SDL_mixer

.if !empty(SDL_MIXER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb2
BUILDLINK_ABI_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.6nb5
BUILDLINK_PKGSRCDIR.SDL_mixer?=	../../audio/SDL_mixer
BUILDLINK_INCDIRS.SDL_mixer?=	include/SDL
.endif	# SDL_MIXER_BUILDLINK3_MK

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
