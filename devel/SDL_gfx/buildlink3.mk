# $NetBSD: buildlink3.mk,v 1.12 2015/04/25 14:20:31 tnn Exp $

BUILDLINK_TREE+=	SDL_gfx

.if !defined(SDL_GFX_BUILDLINK3_MK)
SDL_GFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_gfx+=	SDL_gfx>=2.0.3nb2
BUILDLINK_ABI_DEPENDS.SDL_gfx+=	SDL_gfx>=2.0.24nb1
BUILDLINK_PKGSRCDIR.SDL_gfx?=	../../devel/SDL_gfx

.include "../../devel/SDL/buildlink3.mk"
.endif # SDL_GFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_gfx
