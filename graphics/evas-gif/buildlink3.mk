# $NetBSD: buildlink3.mk,v 1.3 2014/02/12 23:17:59 tron Exp $

BUILDLINK_TREE+=	evas-gif

.if !defined(EVAS_GIF_BUILDLINK3_MK)
EVAS_GIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-gif+=	evas-gif>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-gif?=	evas-gif>=1.7.7nb2
BUILDLINK_PKGSRCDIR.evas-gif?=	../../graphics/evas-gif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"

.endif # EVAS_GIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-gif
