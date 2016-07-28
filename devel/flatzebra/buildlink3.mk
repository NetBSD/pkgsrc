# $NetBSD: buildlink3.mk,v 1.1 2016/07/28 20:26:46 kamil Exp $

BUILDLINK_TREE+=	flatzebra

.if !defined(FLATZEBRA_BUILDLINK3_MK)
FLATZEBRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flatzebra+=	flatzebra>=0.1.6
BUILDLINK_PKGSRCDIR.flatzebra?=		../../devel/flatzebra

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.endif	# FLATZEBRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-flatzebra
