# $NetBSD: buildlink.mk,v 1.7 2001/07/27 13:33:28 jlam Exp $
#
# This Makefile fragment is included by packages that use gdk-pixbuf.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gkd-pixbuf to the dependency version
#     for the version of gdk-pixbuf desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GDK_PIXBUF_BUILDLINK_MK)
GDK_PIXBUF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gkd-pixbuf?=	gdk-pixbuf>=0.8.0nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gkd-pixbuf}:../../graphics/gdk-pixbuf

EVAL_PREFIX+=			BUILDLINK_PREFIX.gdk-pixbuf=gdk-pixbuf
BUILDLINK_PREFIX.gdk-pixbuf_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gdk-pixbuf=	include/gdk-pixbuf/*
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf_xlib.*

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"

BUILDLINK_TARGETS.gdk-pixbuf=	gdk-pixbuf-buildlink
BUILDLINK_TARGETS.gdk-pixbuf+=	gdk-pixbuf-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gdk-pixbuf}

BUILDLINK_CONFIG.gdk-pixbuf=	\
			${BUILDLINK_PREFIX.gdk-pixbuf}/bin/gdk-pixbuf-config
BUILDLINK_CONFIG_WRAPPER.gdk-pixbuf=	\
			${BUILDLINK_DIR}/bin/gdk-pixbuf-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
GDK_PIXBUF_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gdk-pixbuf}
CONFIGURE_ENV+=			GDK_PIXBUF_CONFIG="${GDK_PIXBUF_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gdk-pixbuf}
gdk-pixbuf-buildlink: _BUILDLINK_USE
gdk-pixbuf-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GDK_PIXBUF_BUILDLINK_MK
