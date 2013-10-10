# $NetBSD: buildlink3.mk,v 1.3 2013/10/10 14:41:45 ryoon Exp $

BUILDLINK_TREE+=	evas-svg

.if !defined(EVAS_SVG_BUILDLINK3_MK)
EVAS_SVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-svg+=	evas-svg>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-svg?=	evas-svg>=1.7.7nb2
BUILDLINK_PKGSRCDIR.evas-svg?=	../../graphics/evas-svg

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"

.endif # EVAS_SVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-svg
