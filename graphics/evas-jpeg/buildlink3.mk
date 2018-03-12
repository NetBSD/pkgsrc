# $NetBSD: buildlink3.mk,v 1.5 2018/03/12 11:15:34 wiz Exp $

BUILDLINK_TREE+=	evas-jpeg

.if !defined(EVAS_JPEG_BUILDLINK3_MK)
EVAS_JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-jpeg+=	evas-jpeg>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-jpeg?=	evas-jpeg>=1.7.7nb3
BUILDLINK_PKGSRCDIR.evas-jpeg?=		../../graphics/evas-jpeg

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

.endif # EVAS_JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-jpeg
