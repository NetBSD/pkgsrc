# $NetBSD: buildlink3.mk,v 1.22 2023/11/12 13:21:55 wiz Exp $

BUILDLINK_TREE+=	evas

.if !defined(EVAS_BUILDLINK3_MK)
EVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas+=	evas>=1.7.10
BUILDLINK_ABI_DEPENDS.evas?=	evas>=1.7.10nb4
BUILDLINK_PKGSRCDIR.evas?=	../../graphics/evas

.include "../../devel/eet/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # EVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas
