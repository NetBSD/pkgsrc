# $NetBSD: buildlink2.mk,v 1.3 2004/01/03 18:49:52 reed Exp $

.if !defined(PDFLIB_BUILDLINK2_MK)
PDFLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pdflib
BUILDLINK_DEPENDS.pdflib?=	pdflib>=4.0.3nb2
BUILDLINK_PKGSRCDIR.pdflib?=	../../print/pdflib

EVAL_PREFIX+=				BUILDLINK_PREFIX.pdflib=pdflib
BUILDLINK_PREFIX.pdflib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pdflib=			include/pdflib.h
BUILDLINK_FILES.pdflib+=		lib/libpdf.*

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

BUILDLINK_TARGETS+=	pdflib-buildlink

pdflib-buildlink: _BUILDLINK_USE

.endif	# PDFLIB_BUILDLINK2_MK
