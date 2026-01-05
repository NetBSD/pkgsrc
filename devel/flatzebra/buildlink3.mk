# $NetBSD: buildlink3.mk,v 1.3 2026/01/05 21:32:30 ktnb Exp $

BUILDLINK_TREE+=	flatzebra

.if !defined(FLATZEBRA_BUILDLINK3_MK)
FLATZEBRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flatzebra+=	flatzebra>=0.2.0
BUILDLINK_PKGSRCDIR.flatzebra?=		../../devel/flatzebra

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_gfx/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.endif	# FLATZEBRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-flatzebra
