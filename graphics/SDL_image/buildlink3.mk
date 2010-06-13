# $NetBSD: buildlink3.mk,v 1.21 2010/06/13 22:44:26 wiz Exp $

BUILDLINK_TREE+=	SDL_image

.if !defined(SDL_IMAGE_BUILDLINK3_MK)
SDL_IMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_image+=	SDL_image>=1.2.3nb1
BUILDLINK_ABI_DEPENDS.SDL_image+=	SDL_image>=1.2.10nb2
BUILDLINK_PKGSRCDIR.SDL_image?=	../../graphics/SDL_image
BUILDLINK_INCDIRS.SDL_image?=	include/SDL

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif # SDL_IMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_image
