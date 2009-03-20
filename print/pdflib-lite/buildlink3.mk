# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:15 joerg Exp $

BUILDLINK_TREE+=	pdflib-lite

.if !defined(PDFLIB_LITE_BUILDLINK3_MK)
PDFLIB_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdflib-lite+=	pdflib-lite>=7.0.3
BUILDLINK_PKGSRCDIR.pdflib-lite?=	../../print/pdflib-lite
.endif # PDFLIB_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdflib-lite
