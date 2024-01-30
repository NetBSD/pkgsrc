# $NetBSD: buildlink3.mk,v 1.9 2024/01/30 14:22:07 ryoon Exp $

BUILDLINK_TREE+=	SDL2_gfx

.if !defined(SDL2_GFX_BUILDLINK3_MK)
SDL2_GFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_gfx+=	SDL2_gfx>=1.0.4
BUILDLINK_ABI_DEPENDS.SDL2_gfx?=		SDL2_gfx>=1.0.4nb9
BUILDLINK_PKGSRCDIR.SDL2_gfx?=		../../graphics/SDL2_gfx

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_GFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_gfx
