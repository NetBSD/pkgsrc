# $NetBSD: buildlink3.mk,v 1.4 2004/10/03 00:13:04 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_SOUND_BUILDLINK3_MK:=	${SDL_SOUND_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_sound
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_sound}
BUILDLINK_PACKAGES+=	SDL_sound

.if !empty(SDL_SOUND_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.SDL_sound+=	SDL_sound>=1.0.1
BUILDLINK_RECOMMENDED.SDL_sound+=	SDL_sound>=1.0.1nb1
BUILDLINK_PKGSRCDIR.SDL_sound?=	../../audio/SDL_sound
.endif	# SDL_SOUND_BUILDLINK3_MK

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
