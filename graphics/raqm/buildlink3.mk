# $NetBSD: buildlink3.mk,v 1.5 2026/09/02 19:02:54 wiz Exp $

BUILDLINK_TREE+=	raqm

.if !defined(RAQM_BUILDLINK3_MK)
RAQM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raqm+=	raqm>=0.10.1
BUILDLINK_ABI_DEPENDS.raqm+=	raqm>=0.11.0nb1
BUILDLINK_PKGSRCDIR.raqm?=	../../graphics/raqm

.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif	# RAQM_BUILDLINK3_MK

BUILDLINK_TREE+=	-raqm
