# $NetBSD: buildlink2.mk,v 1.1 2002/09/12 00:32:48 wiz Exp $
#

.if !defined(SDL_IMAGE_BUILDLINK2_MK)
SDL_IMAGE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			SDL-image
BUILDLINK_DEPENDS.SDL-image?=		SDL-image>=1.2.1
BUILDLINK_PKGSRCDIR.SDL-image?=		../../graphics/SDL-image

EVAL_PREFIX+=	BUILDLINK_PREFIX.SDL-image=SDL-image
BUILDLINK_PREFIX.SDL-image_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL-image+=	include/SDL/SDL_image.h
BUILDLINK_FILES.SDL-image+=	lib/libSDL_image-1.2.*
BUILDLINK_FILES.SDL-image+=	lib/libSDL_image.*

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	SDL-image-buildlink

SDL-image-buildlink: _BUILDLINK_USE

.endif	# SDL_IMAGE_BUILDLINK2_MK
