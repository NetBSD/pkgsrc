# $NetBSD: buildlink.mk,v 1.1.1.1 2002/09/14 02:37:40 rh Exp $
#
# This Makefile fragment is included by packages that use gnome-pixmaps.
#
# This file was created automatically using createbuildlink 2.0.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gnome-pixmaps to the dependency pattern
#     for the version of gnome-pixmaps desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GNOME_PIXMAPS_BUILDLINK_MK)
GNOME_PIXMAPS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gnome-pixmaps?=		gnome-pixmaps>=1.4.2
DEPENDS+=	${BUILDLINK_DEPENDS.gnome-pixmaps}:../../graphics/gnome-pixmaps

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-pixmaps=gnome-pixmaps
BUILDLINK_PREFIX.gnome-pixmaps_DEFAULT=	${X11PREFIX}

.include "../../archivers/bzip2/buildlink.mk"

BUILDLINK_TARGETS.gnome-pixmaps=	gnome-pixmaps-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gnome-pixmaps}

pre-configure: ${BUILDLINK_TARGETS}
gnome-pixmaps-buildlink: _BUILDLINK_USE

.endif	# GNOME_PIXMAPS_BUILDLINK_MK
