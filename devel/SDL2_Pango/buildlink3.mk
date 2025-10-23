# $NetBSD: buildlink3.mk,v 1.3 2025/10/23 20:36:14 wiz Exp $

BUILDLINK_TREE+=	SDL2_Pango

.if !defined(SDL2_PANGO_BUILDLINK3_MK)
SDL2_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_Pango+=	SDL2_Pango>=2.1.5
BUILDLINK_ABI_DEPENDS.SDL2_Pango?=	SDL2_Pango>=2.1.5nb3
BUILDLINK_PKGSRCDIR.SDL2_Pango?=	../../devel/SDL2_Pango

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif	# SDL2_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_Pango
