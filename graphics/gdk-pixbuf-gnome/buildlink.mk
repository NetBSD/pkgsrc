# $NetBSD: buildlink.mk,v 1.1 2001/10/01 06:57:25 rh Exp $
#
# This Makefile fragment is included by packages that use gdk-pixbuf-gnome.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gkd-pixbuf to the dependency version
#     for the version of gdk-pixbuf-gnome desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GDK_PIXBUF_GNOME_BUILDLINK_MK)
GDK_PIXBUF_GNOME_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gdk-pixbuf-gnome?=	gdk-pixbuf-gnome>=0.8.0nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gdk-pixbuf-gnome}:../../graphics/gdk-pixbuf-gnome

EVAL_PREFIX+=			BUILDLINK_PREFIX.gdk-pixbuf-gnome=gdk-pixbuf-gnome
BUILDLINK_PREFIX.gdk-pixbuf-gnome_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gdk-pixbuf-gnome=	include/gdk-pixbuf/gnome-canvas-pixbuf.h
BUILDLINK_FILES.gdk-pixbuf-gnome+=	lib/libgnomecanvaspixbuf.*

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"

BUILDLINK_TARGETS.gdk-pixbuf-gnome=	gdk-pixbuf-gnome-buildlink
BUILDLINK_TARGETS.gdk-pixbuf-gnome+=	gdk-pixbuf-gnome-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gdk-pixbuf-gnome}

BUILDLINK_CONFIG.gdk-pixbuf-gnome=	\
			${BUILDLINK_PREFIX.gdk-pixbuf-gnome}/lib/gnomecanvaspixbufConf.sh
BUILDLINK_CONFIG_WRAPPER.gdk-pixbuf-gnome=	\
			${BUILDLINK_DIR}/lib/gnomecanvaspixbufConf.sh

.if defined(USE_CONFIG_WRAPPER)
GDK_PIXBUF_GNOME_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gdk-pixbuf-gnome}
CONFIGURE_ENV+=			GDK_PIXBUF_GNOME_CONFIG="${GDK_PIXBUF_GNOME_CONFIG}"
MAKE_ENV+=			GDK_PIXBUF_GNOME_CONFIG="${GDK_PIXBUF_GNOME_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gdk-pixbuf-gnome}
gdk-pixbuf-gnome-buildlink: _BUILDLINK_USE
gdk-pixbuf-gnome-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GDK_PIXBUF_GNOME_BUILDLINK_MK
