# $NetBSD: buildlink3.mk,v 1.8 2023/01/29 21:14:39 ryoon Exp $

BUILDLINK_TREE+=	evas-xpm

.if !defined(EVAS_XPM_BUILDLINK3_MK)
EVAS_XPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-xpm+=	evas-xpm>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-xpm?=	evas-xpm>=1.7.10nb2
BUILDLINK_PKGSRCDIR.evas-xpm?=		../../graphics/evas-xpm

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.endif # EVAS_XPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-xpm
