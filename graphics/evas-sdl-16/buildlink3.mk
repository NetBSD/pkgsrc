# $NetBSD: buildlink3.mk,v 1.1 2013/06/16 18:56:05 sno Exp $

BUILDLINK_TREE+=	evas-sdl-16

.if !defined(EVAS_SDL_16_BUILDLINK3_MK)
EVAS_SDL_16_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-sdl-16+=	evas-sdl-16>=1.7.7
BUILDLINK_PKGSRCDIR.evas-sdl-16?=	../../graphics/evas-sdl-16

.include "../../devel/SDL/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_SDL_16_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-sdl-16
