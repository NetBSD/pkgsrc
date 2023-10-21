# $NetBSD: buildlink3.mk,v 1.23 2023/10/21 17:11:19 gdt Exp $

BUILDLINK_TREE+=	pdflib

.if !defined(PDFLIB_BUILDLINK3_MK)
PDFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdflib+=	pdflib>=4.0.3nb2
BUILDLINK_ABI_DEPENDS.pdflib+=	pdflib>=4.0.3nb28
BUILDLINK_PKGSRCDIR.pdflib?=	../../print/pdflib

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif # PDFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdflib
