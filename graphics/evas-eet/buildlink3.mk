# $NetBSD: buildlink3.mk,v 1.10 2023/11/12 13:21:55 wiz Exp $

BUILDLINK_TREE+=	evas-eet

.if !defined(EVAS_EET_BUILDLINK3_MK)
EVAS_EET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-eet+=	evas-eet>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-eet?=	evas-eet>=1.7.10nb4
BUILDLINK_PKGSRCDIR.evas-eet?=		../../graphics/evas-eet

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_EET_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-eet
