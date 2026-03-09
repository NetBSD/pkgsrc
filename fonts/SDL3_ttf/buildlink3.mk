# $NetBSD: buildlink3.mk,v 1.1 2026/03/09 11:38:16 adam Exp $

BUILDLINK_TREE+=	SDL3_ttf

.if !defined(SDL3_TTF_BUILDLINK3_MK)
SDL3_TTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL3_ttf+=	SDL3_ttf>=3.2.2
BUILDLINK_ABI_DEPENDS.SDL3_ttf+=	SDL3_ttf>=3.2.2
BUILDLINK_PKGSRCDIR.SDL3_ttf?=		../../fonts/SDL3_ttf

.include "../../devel/SDL3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # SDL3_TTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL3_ttf
