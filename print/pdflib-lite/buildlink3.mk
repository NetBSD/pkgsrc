# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:35:30 wiz Exp $

BUILDLINK_TREE+=	pdflib-lite

.if !defined(PDFLIB_LITE_BUILDLINK3_MK)
PDFLIB_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdflib-lite+=	pdflib-lite>=7.0.3
BUILDLINK_ABI_DEPENDS.pdflib-lite?=	pdflib-lite>=7.0.5nb10
BUILDLINK_PKGSRCDIR.pdflib-lite?=	../../print/pdflib-lite
.endif # PDFLIB_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdflib-lite
