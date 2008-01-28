# $NetBSD: buildlink3.mk,v 1.1 2008/01/28 20:15:57 heinz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_PANGO_BUILDLINK3_MK:=	${SDL_PANGO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	SDL_Pango
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_Pango}
BUILDLINK_PACKAGES+=	SDL_Pango
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}SDL_Pango

.if ${SDL_PANGO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.SDL_Pango+=	SDL_Pango>=0.1.2
BUILDLINK_ABI_DEPENDS.SDL_Pango+=	SDL_Pango>=0.1.2
BUILDLINK_PKGSRCDIR.SDL_Pango?=		../../devel/SDL_Pango
.endif	# SDL_PANGO_BUILDLINK3_MK

# Seems to be unnecessary, pkg-config does not show anything from SDL
#.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
