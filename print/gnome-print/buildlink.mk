# $NetBSD: buildlink.mk,v 1.5 2002/03/26 09:20:44 rh Exp $
#
# This Makefile fragment is included by packages that use gnome-print.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gnome-print to the dependency pattern
#     for the version of gnome-print desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GNOME_PRINT_BUILDLINK_MK)
GNOME_PRINT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gnome-print?=	gnome-print>=0.29nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gnome-print}:../../print/gnome-print

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-print=gnome-print
BUILDLINK_PREFIX.gnome-print_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-print+=	include/gnome-1.0/libgnomeprint/*
BUILDLINK_FILES.gnome-print+=	lib/libgnomeprint.*

.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"

BUILDLINK_TARGETS.gnome-print=	gnome-print-buildlink
BUILDLINK_TARGETS.gnome-print+=	gnome-print-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gnome-print}

BUILDLINK_CONFIG.gnome-print=		${BUILDLINK_PREFIX.gnome-print}/lib/printConf.sh
BUILDLINK_CONFIG_WRAPPER.gnome-print=	${BUILDLINK_DIR}/lib/printConf.sh
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gnome-print}|${BUILDLINK_CONFIG.gnome-print}|g"	\
	-e "s|-I${BUILDLINK_DIR}/\(include/gnome-1.0\)|-I${BUILDLINK_PREFIX.gnome-print}/\1|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${BUILDLINK_PREFIX.gnome-print}/\(include/gnome-1.0\)|-I${BUILDLINK_DIR}/\1|g"

.if defined(USE_CONFIG_WRAPPER)
GNOME_PRINT_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gnome-print}
CONFIGURE_ENV+=		GNOME_PRINT_CONFIG="${GNOME_PRINT_CONFIG}"
MAKE_ENV+=		GNOME_PRINT_CONFIG="${GNOME_PRINT_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gnome-print}
gnome-print-buildlink: _BUILDLINK_USE
gnome-print-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
libart-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GNOME_PRINT_BUILDLINK_MK
