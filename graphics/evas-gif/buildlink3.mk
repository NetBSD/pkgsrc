# $NetBSD: buildlink3.mk,v 1.4 2014/05/15 14:41:51 adam Exp $

BUILDLINK_TREE+=	evas-gif

.if !defined(EVAS_GIF_BUILDLINK3_MK)
EVAS_GIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-gif+=	evas-gif>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-gif?=	evas-gif>=1.7.7nb3
BUILDLINK_PKGSRCDIR.evas-gif?=	../../graphics/evas-gif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"

.endif # EVAS_GIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-gif
