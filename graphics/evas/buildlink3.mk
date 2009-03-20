# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:38 joerg Exp $

BUILDLINK_TREE+=	evas

.if !defined(EVAS_BUILDLINK3_MK)
EVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas+=	evas>=0.9.9.050
BUILDLINK_PKGSRCDIR.evas?=	../../graphics/evas

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # EVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas
