# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:13 rillig Exp $

BUILDLINK_TREE+=	evas-eet

.if !defined(EVAS_EET_BUILDLINK3_MK)
EVAS_EET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-eet+=	evas-eet>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-eet?=	evas-eet>=1.7.7nb2
BUILDLINK_PKGSRCDIR.evas-eet?=		../../graphics/evas-eet

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_EET_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-eet
