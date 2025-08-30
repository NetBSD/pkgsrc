# $NetBSD: buildlink3.mk,v 1.8 2025/08/30 22:45:35 wiz Exp $

BUILDLINK_TREE+=	tesseract

.if !defined(TESSERACT_BUILDLINK3_MK)
TESSERACT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tesseract+=	tesseract>=3.05.01nb6
BUILDLINK_ABI_DEPENDS.tesseract+=	tesseract>=5.5.1nb1
BUILDLINK_PKGSRCDIR.tesseract?=		../../graphics/tesseract

.include "../../graphics/leptonica/buildlink3.mk"
.endif	# TESSERACT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tesseract
