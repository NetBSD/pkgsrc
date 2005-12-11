# $NetBSD: buildlink3.mk,v 1.12 2005/12/11 09:40:38 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SDL_BUILDLINK3_MK:=	${SDL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL}
BUILDLINK_PACKAGES+=	SDL

.if !empty(SDL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.SDL+=		SDL>=1.2.5nb5
BUILDLINK_RECOMMENDED.SDL+=	SDL>=1.2.7nb4
BUILDLINK_PKGSRCDIR.SDL?=	../../devel/SDL
.endif	# SDL_BUILDLINK3_MK

PTHREAD_OPTS+=	require

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "IRIX"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../graphics/aalib/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
