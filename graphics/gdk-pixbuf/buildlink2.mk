# $NetBSD: buildlink2.mk,v 1.3 2002/09/11 10:15:33 jlam Exp $

.if !defined(GDK_PIXBUF_BUILDLINK2_MK)
GDK_PIXBUF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gdk-pixbuf
BUILDLINK_DEPENDS.gdk-pixbuf?=		gdk-pixbuf>=0.17.0
BUILDLINK_PKGSRCDIR.gdk-pixbuf?=	../../graphics/gdk-pixbuf

EVAL_PREFIX+=	BUILDLINK_PREFIX.gdk-pixbuf=gdk-pixbuf
BUILDLINK_PREFIX.gdk-pixbuf_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gdk-pixbuf=	include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf-features.h
BUILDLINK_FILES.gdk-pixbuf+=	include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf-loader.h
BUILDLINK_FILES.gdk-pixbuf+=    include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf-xlib.h
BUILDLINK_FILES.gdk-pixbuf+=	include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf-xlibrgb.h
BUILDLINK_FILES.gdk-pixbuf+=	include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf.h
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-bmp.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-gif.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-ico.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-jpeg.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-png.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-pnm.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-ras.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-tiff.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-xbm.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk-pixbuf/loaders/libpixbufloader-xpm.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf_xlib.*

# The gdk-pixbuf headers should be found at the usual location.
BUILDLINK_TRANSFORM.gdk-pixbuf=	-e "s|/include/gdk-pixbuf-1.0/|/include/|g"

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	gdk-pixbuf-buildlink

gdk-pixbuf-buildlink: _BUILDLINK_USE

.endif	# GDK_PIXBUF_BUILDLINK2_MK
