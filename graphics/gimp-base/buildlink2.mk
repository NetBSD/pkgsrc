# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:24 jlam Exp $

.if !defined(GIMP_BASE_BUILDLINK2_MK)
GIMP_BASE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gimp-base
BUILDLINK_DEPENDS.gimp-base?=	gimp-base>=1.2.3nb1
BUILDLINK_PKGSRCDIR.gimp-base?=	../../graphics/gimp-base
DEPENDS+=		${BUILDLINK_DEPENDS.gimpbase}:../../graphics/gimp-base

EVAL_PREFIX+=		BUILDLINK_PREFIX.gimp-base=gimp-base
BUILDLINK_PREFIX.gimp-base_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gimp-base=	include/libgimp/*
BUILDLINK_FILES.gimp-base+=	lib/libgimp.*
BUILDLINK_FILES.gimp-base+=	lib/libgimpui.*

.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	gimp-base-buildlink

gimp-base-buildlink: _BUILDLINK_USE

.endif	# GIMP_BASE_BUILDLINK2_MK
