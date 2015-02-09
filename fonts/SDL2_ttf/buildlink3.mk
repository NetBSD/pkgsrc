# $NetBSD: buildlink3.mk,v 1.2 2015/02/09 08:43:13 snj Exp $

BUILDLINK_TREE+=	SDL2_ttf

.if !defined(SDL2_TTF_BUILDLINK3_MK)
SDL2_TTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_ttf+=	SDL2_ttf>=2.0.12
BUILDLINK_ABI_DEPENDS.SDL2_ttf?=	SDL2_ttf>=2.0.12nb1
BUILDLINK_PKGSRCDIR.SDL2_ttf?=	../../fonts/SDL2_ttf

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_TTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_ttf
