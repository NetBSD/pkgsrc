# $NetBSD: buildlink.mk,v 1.1 2001/06/16 19:23:18 jlam Exp $
#
# This Makefile fragment is included by packages that use imlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define IMLIB_REQD to the version of imlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(IMLIB_BUILDLINK_MK)
IMLIB_BUILDLINK_MK=	# defined

IMLIB_REQD?=		1.9.8
DEPENDS+=		imlib>=${IMLIB_REQD}:../../graphics/imlib

BUILDLINK_PREFIX.imlib=	${X11PREFIX}
BUILDLINK_FILES.imlib=	include/gdk_imlib.h
BUILDLINK_FILES.imlib+=	include/gdk_imlib_private.h
BUILDLINK_FILES.imlib+=	include/gdk_imlib_types.h
BUILDLINK_FILES.imlib+=	include/Imlib.h
BUILDLINK_FILES.imlib+=	include/Imlib_private.h
BUILDLINK_FILES.imlib+=	include/Imlib_types.h
BUILDLINK_FILES.imlib+=	lib/libImlib.*
BUILDLINK_FILES.imlib+=	lib/libgdk_imlib.*

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/netpbm/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.imlib=	imlib-buildlink
BUILDLINK_TARGETS.imlib+=	imlib-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.imlib}

BUILDLINK_CONFIG.imlib=		${X11PREFIX}/bin/imlib-config
BUILDLINK_CONFIG_WRAPPER.imlib=	${BUILDLINK_DIR}/bin/imlib-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		IMLIB_CONFIG="${BUILDLINK_CONFIG_WRAPPER.imlib}"
.endif

pre-configure: ${BUILDLINK_TARGETS.imlib}
imlib-buildlink: _BUILDLINK_USE
imlib-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# IMLIB_BUILDLINK_MK
