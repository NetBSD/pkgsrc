# $NetBSD: buildlink3.mk,v 1.6 2020/08/17 20:17:28 leot Exp $

BUILDLINK_TREE+=	evas-pmaps

.if !defined(EVAS_PMAPS_BUILDLINK3_MK)
EVAS_PMAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-pmaps+=	evas-pmaps>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-pmaps?=	evas-pmaps>=1.7.10nb1
BUILDLINK_PKGSRCDIR.evas-pmaps?=	../../graphics/evas-pmaps

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_PMAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-pmaps
