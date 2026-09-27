# $NetBSD: buildlink3.mk,v 1.6 2026/09/27 11:37:01 tnn Exp $

BUILDLINK_TREE+=	raqm

.if !defined(RAQM_BUILDLINK3_MK)
RAQM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raqm+=	raqm>=0.10.1
BUILDLINK_ABI_DEPENDS.raqm+=	raqm>=0.11.0nb2
BUILDLINK_PKGSRCDIR.raqm?=	../../graphics/raqm

.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif	# RAQM_BUILDLINK3_MK

BUILDLINK_TREE+=	-raqm
