# $NetBSD: buildlink3.mk,v 1.7 2023/01/29 21:14:38 ryoon Exp $

BUILDLINK_TREE+=	evas-pmaps

.if !defined(EVAS_PMAPS_BUILDLINK3_MK)
EVAS_PMAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-pmaps+=	evas-pmaps>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-pmaps?=	evas-pmaps>=1.7.10nb2
BUILDLINK_PKGSRCDIR.evas-pmaps?=	../../graphics/evas-pmaps

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_PMAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-pmaps
