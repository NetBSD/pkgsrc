# $NetBSD: buildlink3.mk,v 1.1 2013/06/16 18:56:05 sno Exp $

BUILDLINK_TREE+=	evas-png

.if !defined(EVAS_PNG_BUILDLINK3_MK)
EVAS_PNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-png+=	evas-png>=1.7.7
BUILDLINK_PKGSRCDIR.evas-png?=	../../graphics/evas-png

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.endif # EVAS_PNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-png
