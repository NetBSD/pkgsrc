# $NetBSD: buildlink3.mk,v 1.1 2014/02/02 16:06:19 rodent Exp $

BUILDLINK_TREE+=	SDL2_ttf

.if !defined(SDL2_TTF_BUILDLINK3_MK)
SDL2_TTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_ttf+=	SDL2_ttf>=2.0.12
BUILDLINK_PKGSRCDIR.SDL2_ttf?=	../../fonts/SDL2_ttf

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_TTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_ttf
