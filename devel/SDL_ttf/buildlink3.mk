# $NetBSD: buildlink3.mk,v 1.1 2004/03/06 17:47:30 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SDL_TTF_BUILDLINK3_MK:=	${SDL_TTF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_ttf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_ttf}
BUILDLINK_PACKAGES+=	SDL_ttf

.if !empty(SDL_TTF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.SDL_ttf+=	SDL_ttf>=2.0.3nb3
BUILDLINK_PKGSRCDIR.SDL_ttf?=	../../devel/SDL_ttf

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif	# SDL_TTF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
