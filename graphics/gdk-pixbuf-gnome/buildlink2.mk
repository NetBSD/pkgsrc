# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:24 jlam Exp $

.if !defined(GDK_PIXBUF_GNOME_BUILDLINK2_MK)
GDK_PIXBUF_GNOME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gdk-pixbuf-gnome
BUILDLINK_DEPENDS.gdk-pixbuf-gnome?=	gdk-pixbuf-gnome>=0.11.0nb1
BUILDLINK_PKGSRCDIR.gdk-pixbuf-gnome?=	../../graphics/gdk-pixbuf-gnome

EVAL_PREFIX+=		BUILDLINK_PREFIX.gdk-pixbuf-gnome=gdk-pixbuf-gnome
BUILDLINK_PREFIX.gdk-pixbuf-gnome_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gdk-pixbuf-gnome=	include/gdk-pixbuf-1.0/gdk-pixbuf/gnome-canvas-pixbuf.h
BUILDLINK_FILES.gdk-pixbuf-gnome+=	lib/libgnomecanvaspixbuf.*

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

BUILDLINK_TARGETS+=	gdk-pixbuf-gnome-buildlink

gdk-pixbuf-gnome-buildlink: _BUILDLINK_USE

.endif	# GDK_PIXBUF_GNOME_BUILDLINK2_MK
