# $NetBSD: buildlink3.mk,v 1.2 2004/02/09 23:56:32 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PDFLIB_BUILDLINK3_MK:=	${PDFLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pdflib
.endif

.if !empty(PDFLIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		pdflib
BUILDLINK_DEPENDS.pdflib+=	pdflib>=4.0.3nb2
BUILDLINK_PKGSRCDIR.pdflib?=	../../print/pdflib

.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.endif # PDFLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
