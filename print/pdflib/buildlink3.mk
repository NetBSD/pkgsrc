# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:25:15 joerg Exp $

BUILDLINK_TREE+=	pdflib

.if !defined(PDFLIB_BUILDLINK3_MK)
PDFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdflib+=	pdflib>=4.0.3nb2
BUILDLINK_ABI_DEPENDS.pdflib+=	pdflib>=4.0.3nb7
BUILDLINK_PKGSRCDIR.pdflib?=	../../print/pdflib

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif # PDFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdflib
