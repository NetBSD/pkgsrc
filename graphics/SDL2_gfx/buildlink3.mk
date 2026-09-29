# $NetBSD: buildlink3.mk,v 1.16 2026/09/29 06:05:31 wiz Exp $

BUILDLINK_TREE+=	SDL2_gfx

.if !defined(SDL2_GFX_BUILDLINK3_MK)
SDL2_GFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_gfx+=	SDL2_gfx>=1.0.4
BUILDLINK_ABI_DEPENDS.SDL2_gfx?=		SDL2_gfx>=1.0.4nb16
BUILDLINK_PKGSRCDIR.SDL2_gfx?=		../../graphics/SDL2_gfx

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_GFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_gfx
