# $NetBSD: buildlink3.mk,v 1.1 2004/02/08 23:17:10 jmmv Exp $
#
# This Makefile fragment is included by packages that use pdflib.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PDFLIB_BUILDLINK3_MK:=	${PDFLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pdflib
.endif

.if !empty(PDFLIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pdflib
BUILDLINK_DEPENDS.pdflib?=		pdflib>=4.0.3nb2
BUILDLINK_PKGSRCDIR.pdflib?=		../../print/pdflib

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif # PDFLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
