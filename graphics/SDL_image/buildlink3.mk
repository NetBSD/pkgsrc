# $NetBSD: buildlink3.mk,v 1.3 2004/01/05 11:05:45 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_IMAGE_BUILDLINK3_MK:=	${SDL_IMAGE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_image
.endif

.if !empty(SDL_IMAGE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		SDL_image
BUILDLINK_DEPENDS.SDL_image?=	SDL_image>=1.2.2nb2
BUILDLINK_PKGSRCDIR.SDL_image?=	../../graphics/SDL_image
BUILDLINK_INCDIRS.SDL_image?=	include/SDL

.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.  include "../../devel/SDL/buildlink3.mk"
.endif	# SDL_IMAGE_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
