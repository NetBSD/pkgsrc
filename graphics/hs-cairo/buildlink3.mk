# $NetBSD: buildlink3.mk,v 1.5 2026/09/02 19:02:41 wiz Exp $

BUILDLINK_TREE+=	hs-cairo

.if !defined(HS_CAIRO_BUILDLINK3_MK)
HS_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cairo+=	hs-cairo>=0.13.11
BUILDLINK_ABI_DEPENDS.hs-cairo+=	hs-cairo>=0.13.11.0nb4
BUILDLINK_PKGSRCDIR.hs-cairo?=		../../graphics/hs-cairo

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# HS_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cairo
