# $NetBSD: buildlink3.mk,v 1.1 2004/03/07 06:58:39 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_SOUND_BUILDLINK3_MK:=	${SDL_SOUND_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_sound
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_sound}
BUILDLINK_PACKAGES+=	SDL_sound

.if !empty(SDL_SOUND_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.SDL_sound+=	SDL_sound>=1.0.1
BUILDLINK_PKGSRCDIR.SDL_sound?=	../../audio/SDL_sound

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/smpeg/buildlink3.mk"

.endif	# SDL_SOUND_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
