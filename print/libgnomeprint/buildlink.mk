# $NetBSD: buildlink.mk,v 1.1.1.1 2002/07/12 17:15:54 wiz Exp $
#
# This Makefile fragment is included by packages that use the library
# provided by libgnomeprint.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libgnomeprint to the dependency
#     pattern for the version of libgnomeprint desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBGNOMEPRINT_BUILDLINK_MK)
LIBGNOMEPRINT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libgnomeprint?=	libgnomeprint>=1.115.0
DEPENDS+=	${BUILDLINK_DEPENDS.libgnomeprint}:../../graphics/libgnomeprint

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgnomeprint=libgnomeprint
BUILDLINK_PREFIX.libgnomeprint=	${LOCALBASE}
BUILDLINK_FILES.libgnomeprint=	bin/libgnomeprint-2.0-font-install
BUILDLINK_FILES.libgnomeprint+=	include/libgnomeprint-2.0/libgnomeprint/*
BUILDLINK_FILES.libgnomeprint+=	include/libgnomeprint-2.0/libgnomeprint/private/*
BUILDLINK_FILES.libgnomeprint+=	lib/gnome-print-2.0/drivers/*
BUILDLINK_FILES.libgnomeprint+=	lib/gnome-print-2.0/transports/*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint-2.*
BUILDLINK_FILES.libgnomeprint+=	lib/pkgconfig/libgnomeprint-2.0.pc


BUILDLINK_TARGETS.libgnomeprint=	libgnomeprint-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libgnomeprint}

pre-configure: ${BUILDLINK_TARGETS.libgnomeprint}
libgnomeprint-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMEPRINT_BUILDLINK_MK
