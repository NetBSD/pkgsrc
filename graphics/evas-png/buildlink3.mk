# $NetBSD: buildlink3.mk,v 1.2 2014/02/12 23:18:00 tron Exp $

BUILDLINK_TREE+=	evas-png

.if !defined(EVAS_PNG_BUILDLINK3_MK)
EVAS_PNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-png+=	evas-png>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-png?=	evas-png>=1.7.7nb1
BUILDLINK_PKGSRCDIR.evas-png?=	../../graphics/evas-png

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.endif # EVAS_PNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-png
