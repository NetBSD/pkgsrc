# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/03/29 22:06:48 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gimp-base.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GIMP_BASE_BUILDLINK2_MK)
GIMP_BASE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gimp-base
BUILDLINK_DEPENDS.gimp-base?=		gimp-base>=1.2.5nb2
BUILDLINK_PKGSRCDIR.gimp-base?=		../../graphics/gimp-base

EVAL_PREFIX+=	BUILDLINK_PREFIX.gimp-base=gimp-base
BUILDLINK_PREFIX.gimp-base_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gimp-base+=	include/gck/*
BUILDLINK_FILES.gimp-base+=	include/libgimp/*
BUILDLINK_FILES.gimp-base+=	lib/libgck*
BUILDLINK_FILES.gimp-base+=	lib/libgimp*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/mpeg-lib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	gimp-base-buildlink

gimp-base-buildlink: _BUILDLINK_USE

.endif	# GIMP_BASE_BUILDLINK2_MK
