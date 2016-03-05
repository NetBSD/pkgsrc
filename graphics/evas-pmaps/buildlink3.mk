# $NetBSD: buildlink3.mk,v 1.3 2016/03/05 11:27:48 jperkin Exp $

BUILDLINK_TREE+=	evas-pmaps

.if !defined(EVAS_PMAPS_BUILDLINK3_MK)
EVAS_PMAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-pmaps+=	evas-pmaps>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-pmaps?=	evas-pmaps>=1.7.7nb2
BUILDLINK_PKGSRCDIR.evas-pmaps?=	../../graphics/evas-pmaps

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_PMAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-pmaps
