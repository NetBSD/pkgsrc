# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/03 08:20:01 wiz Exp $
#

.if !defined(SDL_IMAGE_BUILDLINK2_MK)
SDL_IMAGE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			SDL_image
BUILDLINK_DEPENDS.SDL_image?=		SDL_image>=1.2.1
BUILDLINK_PKGSRCDIR.SDL_image?=		../../graphics/SDL_image

EVAL_PREFIX+=	BUILDLINK_PREFIX.SDL_image=SDL_image
BUILDLINK_PREFIX.SDL_image_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL_image+=	include/SDL/SDL_image.h
BUILDLINK_FILES.SDL_image+=	lib/libSDL_image-1.2.*
BUILDLINK_FILES.SDL_image+=	lib/libSDL_image.*

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	SDL_image-buildlink

SDL_image-buildlink: _BUILDLINK_USE

.endif	# SDL_IMAGE_BUILDLINK2_MK
