# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/16 03:37:03 rh Exp $
#
# This Makefile fragment is included by packages that use gtkglext.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(GTKGLEXT_BUILDLINK2_MK)
GTKGLEXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtkglext
BUILDLINK_DEPENDS.gtkglext?=		gtkglext>=0.5.1
BUILDLINK_PKGSRCDIR.gtkglext?=		../../graphics/gtkglext

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtkglext=gtkglext
BUILDLINK_PREFIX.gtkglext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkgl.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglconfig.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglcontext.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkgldebug.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkgldefs.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkgldrawable.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglenumtypes.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglfont.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglpixmap.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglprivate.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglquery.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkgltokens.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkgltypes.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglversion.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglwindow.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gdk/gdkglx.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gtk/gtkgl.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gtk/gtkgldebug.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gtk/gtkgldefs.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gtk/gtkglprivate.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gtk/gtkglversion.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gtk/gtkglwidget.h
BUILDLINK_FILES.gtkglext+=	include/gtkglext-0.x/gtk/gtkglwidgetparam.h
BUILDLINK_FILES.gtkglext+=	lib/libgdkglext-x11-0.x.*
BUILDLINK_FILES.gtkglext+=	lib/libgtkglext-x11-0.x.*
BUILDLINK_FILES.gtkglext+=	lib/pkgconfig/gdkglext-0.x.pc
BUILDLINK_FILES.gtkglext+=	lib/pkgconfig/gdkglext-x11-0.x.pc
BUILDLINK_FILES.gtkglext+=	lib/pkgconfig/gtkglext-0.x.pc
BUILDLINK_FILES.gtkglext+=	lib/pkgconfig/gtkglext-x11-0.x.pc

.include "../../textproc/gtk-doc/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkglext-buildlink

gtkglext-buildlink: _BUILDLINK_USE

.endif	# GTKGLEXT_BUILDLINK2_MK
