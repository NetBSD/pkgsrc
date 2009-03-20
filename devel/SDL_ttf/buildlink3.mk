# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:09 joerg Exp $

BUILDLINK_TREE+=	SDL_ttf

.if !defined(SDL_TTF_BUILDLINK3_MK)
SDL_TTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_ttf+=	SDL_ttf>=2.0.3nb3
BUILDLINK_ABI_DEPENDS.SDL_ttf?=	SDL_ttf>=2.0.8
BUILDLINK_PKGSRCDIR.SDL_ttf?=	../../devel/SDL_ttf

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # SDL_TTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_ttf
