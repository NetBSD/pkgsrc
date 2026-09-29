# $NetBSD: buildlink3.mk,v 1.7 2026/09/29 06:05:44 wiz Exp $

BUILDLINK_TREE+=	hs-cairo

.if !defined(HS_CAIRO_BUILDLINK3_MK)
HS_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cairo+=	hs-cairo>=0.13.11
BUILDLINK_ABI_DEPENDS.hs-cairo+=	hs-cairo>=0.13.11.0nb6
BUILDLINK_PKGSRCDIR.hs-cairo?=		../../graphics/hs-cairo

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# HS_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cairo
