# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:30 jlam Exp $

.if !defined(GDK_PIXBUF_BUILDLINK2_MK)
GDK_PIXBUF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gdk-pixbuf
BUILDLINK_DEPENDS.gdk-pixbuf?=		gdk-pixbuf>=0.11.0nb1
BUILDLINK_PKGSRCDIR.gdk-pixbuf?=	../../graphics/gdk-pixbuf

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
