# $NetBSD: buildlink3.mk,v 1.8 2011/11/01 06:01:32 sbd Exp $

BUILDLINK_TREE+=	evas

.if !defined(EVAS_BUILDLINK3_MK)
EVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas+=	evas>=0.9.9.062
BUILDLINK_ABI_DEPENDS.evas?=	evas>=0.9.9.063nb3
BUILDLINK_PKGSRCDIR.evas?=	../../graphics/evas

.include "../../devel/eet/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # EVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas
