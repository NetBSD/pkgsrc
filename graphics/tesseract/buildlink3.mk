# $NetBSD: buildlink3.mk,v 1.3 2021/07/16 09:16:27 jperkin Exp $

BUILDLINK_TREE+=	tesseract

.if !defined(TESSERACT_BUILDLINK3_MK)
TESSERACT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tesseract+=	tesseract>=3.05.01nb6
BUILDLINK_ABI_DEPENDS.tesseract?=	tesseract>=4.1.1nb5
BUILDLINK_PKGSRCDIR.tesseract?=		../../graphics/tesseract

.include "../../graphics/leptonica/buildlink3.mk"
.endif	# TESSERACT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tesseract
