# $NetBSD: buildlink3.mk,v 1.2 2014/02/12 23:18:00 tron Exp $

BUILDLINK_TREE+=	evas-xpm

.if !defined(EVAS_XPM_BUILDLINK3_MK)
EVAS_XPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-xpm+=	evas-xpm>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-xpm?=	evas-xpm>=1.7.7nb1
BUILDLINK_PKGSRCDIR.evas-xpm?=	../../graphics/evas-xpm

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.endif # EVAS_XPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-xpm
