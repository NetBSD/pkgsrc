# $NetBSD: buildlink3.mk,v 1.25 2025/08/30 22:46:11 wiz Exp $

BUILDLINK_TREE+=	pdflib

.if !defined(PDFLIB_BUILDLINK3_MK)
PDFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdflib+=	pdflib>=4.0.3nb2
BUILDLINK_ABI_DEPENDS.pdflib+=	pdflib>=4.0.3nb30
BUILDLINK_PKGSRCDIR.pdflib?=	../../print/pdflib

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif # PDFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdflib
