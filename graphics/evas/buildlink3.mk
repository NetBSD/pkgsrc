# $NetBSD: buildlink3.mk,v 1.17 2020/01/18 21:48:12 jperkin Exp $

BUILDLINK_TREE+=	evas

.if !defined(EVAS_BUILDLINK3_MK)
EVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas+=	evas>=1.7.7
BUILDLINK_ABI_DEPENDS.evas?=	evas>=1.7.7nb5
BUILDLINK_PKGSRCDIR.evas?=	../../graphics/evas

.include "../../devel/eet/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # EVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas
