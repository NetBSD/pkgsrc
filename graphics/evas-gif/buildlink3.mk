# $NetBSD: buildlink3.mk,v 1.10 2020/06/05 12:48:59 jperkin Exp $

BUILDLINK_TREE+=	evas-gif

.if !defined(EVAS_GIF_BUILDLINK3_MK)
EVAS_GIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-gif+=	evas-gif>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-gif?=	evas-gif>=1.7.10nb1
BUILDLINK_PKGSRCDIR.evas-gif?=		../../graphics/evas-gif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"

.endif # EVAS_GIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-gif
