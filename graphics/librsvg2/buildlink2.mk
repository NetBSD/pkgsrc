# $NetBSD: buildlink2.mk,v 1.8 2003/12/14 21:35:11 jmmv Exp $
#
# This Makefile fragment is included by packages that use librsvg2.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBRSVG2_BUILDLINK2_MK)
LIBRSVG2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			librsvg2
BUILDLINK_DEPENDS.librsvg2?=		librsvg2>=2.4.0
BUILDLINK_PKGSRCDIR.librsvg2?=		../../graphics/librsvg2

EVAL_PREFIX+=	BUILDLINK_PREFIX.librsvg2=librsvg2
BUILDLINK_PREFIX.librsvg2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.librsvg2+=	include/librsvg-2/librsvg/*
BUILDLINK_FILES.librsvg2+=	lib/gtk-2.0/2.2.0/engines/libsvg.*
BUILDLINK_FILES.librsvg2+=	lib/gtk-2.0/2.2.0/loaders/svg_loader.*
BUILDLINK_FILES.librsvg2+=	lib/librsvg-2.*

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	librsvg2-buildlink

librsvg2-buildlink: _BUILDLINK_USE

.endif	# LIBRSVG2_BUILDLINK2_MK
