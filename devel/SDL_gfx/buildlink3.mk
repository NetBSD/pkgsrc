# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:09 joerg Exp $

BUILDLINK_TREE+=	SDL_gfx

.if !defined(SDL_GFX_BUILDLINK3_MK)
SDL_GFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_gfx+=	SDL_gfx>=2.0.3nb2
BUILDLINK_ABI_DEPENDS.SDL_gfx+=	SDL_gfx>=2.0.15
BUILDLINK_PKGSRCDIR.SDL_gfx?=	../../devel/SDL_gfx

.include "../../devel/SDL/buildlink3.mk"
.endif # SDL_GFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_gfx
