# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:55:17 wiz Exp $

.if !defined(GIMP_BASE_BUILDLINK2_MK)
GIMP_BASE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gimp-base
BUILDLINK_DEPENDS.gimp-base?=	gimp-base>=1.2.3nb5
BUILDLINK_PKGSRCDIR.gimp-base?=	../../graphics/gimp-base
DEPENDS+=		${BUILDLINK_DEPENDS.gimp-base}:../../graphics/gimp-base

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
