# $NetBSD: buildlink3.mk,v 1.8 2004/10/03 00:14:48 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_IMAGE_BUILDLINK3_MK:=	${SDL_IMAGE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_image
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_image}
BUILDLINK_PACKAGES+=	SDL_image

.if !empty(SDL_IMAGE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.SDL_image+=	SDL_image>=1.2.3nb1
BUILDLINK_RECOMMENDED.SDL_image+=	SDL_image>=1.2.3nb2
BUILDLINK_PKGSRCDIR.SDL_image?=	../../graphics/SDL_image
BUILDLINK_INCDIRS.SDL_image?=	include/SDL
.endif	# SDL_IMAGE_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
