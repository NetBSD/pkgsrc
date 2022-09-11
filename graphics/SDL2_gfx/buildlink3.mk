# $NetBSD: buildlink3.mk,v 1.7 2022/09/11 12:51:07 wiz Exp $

BUILDLINK_TREE+=	SDL2_gfx

.if !defined(SDL2_GFX_BUILDLINK3_MK)
SDL2_GFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_gfx+=	SDL2_gfx>=1.0.4
BUILDLINK_ABI_DEPENDS.SDL2_gfx?=		SDL2_gfx>=1.0.4nb7
BUILDLINK_PKGSRCDIR.SDL2_gfx?=		../../graphics/SDL2_gfx

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_GFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_gfx
