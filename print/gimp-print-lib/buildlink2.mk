# $NetBSD: buildlink2.mk,v 1.3 2002/11/27 16:12:37 drochner Exp $

.if !defined(GIMP_PRINT_BUILDLINK2_MK)
GIMP_PRINT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=	gimp-print-lib
BUILDLINK_DEPENDS.gimp-print-lib?=	gimp-print-lib-4.2.4
BUILDLINK_PKGSRCDIR.gimp-print-lib?=	../../print/gimp-print-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.gimp-print-lib=gimp-print-lib
BUILDLINK_PREFIX.gimp-print-lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gimp-print-lib=		include/gimp-print/*
BUILDLINK_FILES.gimp-print-lib+=	lib/libgimpprint.*

BUILDLINK_TARGETS+=	gimp-print-lib-buildlink

gimp-print-lib-buildlink: _BUILDLINK_USE

.endif	# GIMP_PRINT_BUILDLINK2_MK
