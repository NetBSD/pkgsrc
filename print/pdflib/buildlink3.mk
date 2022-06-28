# $NetBSD: buildlink3.mk,v 1.21 2022/06/28 11:35:30 wiz Exp $

BUILDLINK_TREE+=	pdflib

.if !defined(PDFLIB_BUILDLINK3_MK)
PDFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdflib+=	pdflib>=4.0.3nb2
BUILDLINK_ABI_DEPENDS.pdflib+=	pdflib>=4.0.3nb26
BUILDLINK_PKGSRCDIR.pdflib?=	../../print/pdflib

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif # PDFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdflib
