# $NetBSD: buildlink3.mk,v 1.6 2026/09/27 11:36:47 tnn Exp $

BUILDLINK_TREE+=	hs-cairo

.if !defined(HS_CAIRO_BUILDLINK3_MK)
HS_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cairo+=	hs-cairo>=0.13.11
BUILDLINK_ABI_DEPENDS.hs-cairo+=	hs-cairo>=0.13.11.0nb5
BUILDLINK_PKGSRCDIR.hs-cairo?=		../../graphics/hs-cairo

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# HS_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cairo
