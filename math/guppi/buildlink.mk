# $NetBSD: buildlink.mk,v 1.2 2002/09/09 21:26:05 wiz Exp $
#
# This Makefile fragment is included by packages that use guppi.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.guppi to the dependency pattern
#     for the version of gupp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GUPPI_BUILDLINK_MK)
GUPPI_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.guppi?=	guppi>=0.40.3
DEPENDS+=	${BUILDLINK_DEPENDS.guppi}:../../math/guppi

EVAL_PREFIX+=			BUILDLINK_PREFIX.guppi=guppi
BUILDLINK_PREFIX.guppi=	${X11PREFIX}
BUILDLINK_FILES.guppi+=	include/gnome-1.0/libguppi/*
BUILDLINK_FILES.guppi+=	include/gnome-1.0/libguppitank/*
BUILDLINK_FILES.guppi+=	lib/libguppi*

BUILDLINK_TARGETS.guppi=	guppi-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.guppi}

pre-configure: ${BUILDLINK_TARGETS.guppi}
guppi-buildlink: _BUILDLINK_USE

.endif	# GUPPI_BUILDLINK_MK
