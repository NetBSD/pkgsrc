# $NetBSD: buildlink2.mk,v 1.3 2002/09/17 20:27:48 drochner Exp $

.if !defined(CUPS_BUILDLINK2_MK)
CUPS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		cups
BUILDLINK_DEPENDS.cups?=	cups>=1.1.14nb1
BUILDLINK_PKGSRCDIR.cups?=	../../print/cups

EVAL_PREFIX+=	BUILDLINK_PREFIX.cups=cups
BUILDLINK_PREFIX.cups_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cups=	include/cups/*
BUILDLINK_FILES.cups+=	lib/libcups.*
BUILDLINK_FILES.cups+=	lib/libcupsimage.*

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

BUILDLINK_TARGETS+=	cups-buildlink

cups-buildlink: _BUILDLINK_USE

.endif	# CUPS_BUILDLINK2_MK
