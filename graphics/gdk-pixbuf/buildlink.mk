# $NetBSD: buildlink.mk,v 1.16 2002/08/25 18:39:04 jlam Exp $
#
# This Makefile fragment is included by packages that use gdk-pixbuf.
#
# This file was created automatically using createbuildlink 1.5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gdk-pixbuf to the dependency pattern
#     for the version of gdk-pixbuf desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GDK_PIXBUF_BUILDLINK_MK)
GDK_PIXBUF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gdk-pixbuf?=		gdk-pixbuf>=0.17.0
DEPENDS+=	${BUILDLINK_DEPENDS.gdk-pixbuf}:../../graphics/gdk-pixbuf

EVAL_PREFIX+=	BUILDLINK_PREFIX.gdk-pixbuf=gdk-pixbuf
BUILDLINK_PREFIX.gdk-pixbuf_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gdk-pixbuf+=	include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf-features.h
BUILDLINK_FILES.gdk-pixbuf+=	include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf-loader.h
BUILDLINK_FILES.gdk-pixbuf+=	include/gdk-pixbuf-1.0/gdk-pixbuf/gdk-pixbuf-xlib.h
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
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk_pixbufConf.sh
BUILDLINK_FILES.gdk-pixbuf+=	lib/gdk_pixbuf_xlibConf.sh
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf.*
BUILDLINK_FILES.gdk-pixbuf+=	lib/libgdk_pixbuf_xlib.*

# The gdk-pixbuf headers should be found at the usual location.
BUILDLINK_TRANSFORM.gdk-pixbuf=	-e "s|/include/gdk-pixbuf-1.0/|/include/|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${BUILDLINK_PREFIX.gdk-pixbuf}/include/gdk-pixbuf-1.0 |-I${BUILDLINK_DIR}/include/gdk-pixbuf-1.0 -I${BUILDLINK_DIR}/include/ |g"

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.gdk-pixbuf=	gdk-pixbuf-buildlink
BUILDLINK_TARGETS.gdk-pixbuf+=	gdk-pixbuf-gdk-pixbuf-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gdk-pixbuf}

BUILDLINK_CONFIG.gdk-pixbuf-gdk-pixbuf=					\
	${BUILDLINK_PREFIX.gdk-pixbuf}/bin/gdk-pixbuf-config
BUILDLINK_CONFIG_WRAPPER.gdk-pixbuf-gdk-pixbuf=				\
	${BUILDLINK_DIR}/bin/gdk-pixbuf-config
REPLACE_BUILDLINK_SED+=							\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gdk-pixbuf-gdk-pixbuf}|${BUILDLINK_CONFIG.gdk-pixbuf-gdk-pixbuf}|g"

BUILDLINK_CONFIG_WRAPPER_SED+=						\
	-e "s|-I[ 	]*${BUILDLINK_PREFIX.gdk-pixbuf}/include/gdk-pixbuf-1.0/gdk-pixbuf|-I${BUILDLINK_DIR}/include/gdk-pixbuf-1.0/gdk-pixbuf|g"
REPLACE_BUILDLINK_SED+=							\
	-e "s|-I${BUILDLINK_DIR}/include/gdk-pixbuf-1.0/gdk-pixbuf|-I${BUILDLINK_PREFIX.gdk-pixbuf}/include/gdk-pixbuf-1.0/gdk-pixbuf|g"
BUILDLINK_CONFIG_WRAPPER_SED+=						\
	-e "s|-I[ 	]*${BUILDLINK_PREFIX.gdk-pixbuf}/include/gdk-pixbuf-1.0|-I${BUILDLINK_DIR}/include/gdk-pixbuf-1.0|g"
REPLACE_BUILDLINK_SED+=							\
	-e "s|-I${BUILDLINK_DIR}/include/gdk-pixbuf-1.0|-I${BUILDLINK_PREFIX.gdk-pixbuf}/include/gdk-pixbuf-1.0|g"
BUILDLINK_CONFIG_WRAPPER_SED+=						\
	-e "s|-L[ 	]*${BUILDLINK_PREFIX.gdk-pixbuf}/lib/gdk-pixbuf/loaders|-L${BUILDLINK_DIR}/lib/gdk-pixbuf/loaders|g"
REPLACE_BUILDLINK_SED+=							\
	-e "s|-L${BUILDLINK_DIR}/lib/gdk-pixbuf/loaders|-L${BUILDLINK_PREFIX.gdk-pixbuf}/lib/gdk-pixbuf/loaders|g"
BUILDLINK_CONFIG_WRAPPER_SED+=						\
	-e "s|-L[ 	]*${BUILDLINK_PREFIX.gdk-pixbuf}/lib/gdk-pixbuf|-L${BUILDLINK_DIR}/lib/gdk-pixbuf|g"
REPLACE_BUILDLINK_SED+=							\
	-e "s|-L${BUILDLINK_DIR}/lib/gdk-pixbuf|-L${BUILDLINK_PREFIX.gdk-pixbuf}/lib/gdk-pixbuf|g"

.if defined(USE_CONFIG_WRAPPER)
GDK_PIXBUF_GDK_PIXBUF_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gdk-pixbuf-gdk-pixbuf}
CONFIGURE_ENV+=		GDK_PIXBUF_GDK_PIXBUF_CONFIG="${GDK_PIXBUF_GDK_PIXBUF_CONFIG}"
MAKE_ENV+=		GDK_PIXBUF_GDK_PIXBUF_CONFIG="${GDK_PIXBUF_GDK_PIXBUF_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS}
gdk-pixbuf-buildlink: _BUILDLINK_USE
gdk-pixbuf-gdk-pixbuf-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GDK_PIXBUF_BUILDLINK_MK
