# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:39 jlam Exp $
#
# This Makefile fragment is included by packages that use gdk-pixbuf.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gkd-pixbuf to the dependency version
#     for the version of gdk-pixbuf desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(GDK_PIXBUF_BUILDLINK2_MK)
GDK_PIXBUF_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.gdk-pixbuf?=	gdk-pixbuf>=0.11.0nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gdk-pixbuf}:../../graphics/gdk-pixbuf

EVAL_PREFIX+=	BUILDLINK_PREFIX.gdk-pixbuf=gdk-pixbuf
BUILDLINK_PREFIX.gdk-pixbuf_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gdk-pixbuf=	include/gdk-pixbuf/*
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf_xlib.*

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	gdk-pixbuf-buildlink

gdk-pixbuf-buildlink: _BUILDLINK_USE

.endif	# GDK_PIXBUF_BUILDLINK2_MK
