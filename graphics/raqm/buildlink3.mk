# $NetBSD: buildlink3.mk,v 1.2 2024/07/11 19:43:10 wiz Exp $

BUILDLINK_TREE+=	raqm

.if !defined(RAQM_BUILDLINK3_MK)
RAQM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raqm+=	raqm>=0.10.1
BUILDLINK_PKGSRCDIR.raqm?=	../../graphics/raqm

.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif	# RAQM_BUILDLINK3_MK

BUILDLINK_TREE+=	-raqm
