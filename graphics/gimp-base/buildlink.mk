# $NetBSD: buildlink.mk,v 1.1.1.1 2002/02/15 20:52:36 drochner Exp $
#
# This Makefile fragment is included by packages that use gtk.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gtk to the dependency pattern
#     for the version of gtk desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GIMPBASE_BUILDLINK_MK)
GIMPBASE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gimpbase?=	gimp-base>=1.2.3
DEPENDS+=		${BUILDLINK_DEPENDS.gimpbase}:../../graphics/gimp-base

EVAL_PREFIX+=		BUILDLINK_PREFIX.gimpbase=gimp-base
BUILDLINK_PREFIX.gimpbase_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gimpbase=	include/libgimp/*
BUILDLINK_FILES.gimpbase+=	lib/libgimp.*
BUILDLINK_FILES.gimpbase+=	lib/libgimpui.*

.include "../../devel/glib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.gimpbase=	gimpbase-buildlink
BUILDLINK_TARGETS.gimpbase+=	gimpbase-buildlink-config-wrapper
BUILDLINK_TARGETS.gimpbase+=	gimptool-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gimpbase}

BUILDLINK_CONFIG.gimpbase=	${BUILDLINK_PREFIX.gimpbase}/bin/gimp-config
BUILDLINK_CONFIG_WRAPPER.gimpbase=	${BUILDLINK_DIR}/bin/gimp-config
BUILDLINK_CONFIG.gimptool=	${BUILDLINK_PREFIX.gimpbase}/bin/gimptool
BUILDLINK_CONFIG_WRAPPER.gimptool=	${BUILDLINK_DIR}/bin/gimptool
REPLACE_BUILDLINK_SED+=	\
 -e "s|${BUILDLINK_CONFIG_WRAPPER.gimpbase}|${BUILDLINK_CONFIG.gimpbase}|g"
REPLACE_BUILDLINK_SED+= \
 -e "s|${BUILDLINK_CONFIG_WRAPPER.gimptool}|${BUILDLINK_CONFIG.gimptool}|g"

.if defined(USE_CONFIG_WRAPPER)
GIMPTOOL?=	${BUILDLINK_CONFIG_WRAPPER.gimptool}
CONFIGURE_ENV+=	GIMPTOOL="${GIMPTOOL}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gimpbase}
gimpbase-buildlink: _BUILDLINK_USE
gimpbase-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
gimptool-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GIMPBASE_BUILDLINK_MK
