# $NetBSD: buildlink3.mk,v 1.9 2004/10/03 00:13:24 tv Exp $

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

USE_X11=	yes
PTHREAD_OPTS+=	require

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "IRIX"
.include "../../graphics/Mesa/buildlink3.mk"
.endif
.include "../../graphics/aalib-x11/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
