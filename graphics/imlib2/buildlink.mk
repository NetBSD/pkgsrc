# $NetBSD: buildlink.mk,v 1.1.1.1 2001/08/16 10:49:52 rh Exp $
#
# This Makefile fragment is included by packages that use imlib2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.imlib2 to the dependency pattern
#     for the version of imlib2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(IMLIB2_BUILDLINK_MK)
IMLIB2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.imlib2?=	imlib2>=1.0.3
DEPENDS+=	${BUILDLINK_DEPENDS.imlib2}:../../graphics/imlib2

EVAL_PREFIX+=		BUILDLINK_PREFIX.imlib2=imlib2
BUILDLINK_PREFIX.imlib2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.imlib2=		include/Imlib2.h
BUILDLINK_FILES.imlib2+=	lib/libImlib2.*
BUILDLINK_FILES.imlib2+=	lib/loaders/image/*

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../databases/edb/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.imlib2=	imlib2-buildlink
BUILDLINK_TARGETS.imlib2+=	imlib2-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.imlib2}

BUILDLINK_CONFIG.imlib2=		${BUILDLINK_PREFIX.imlib2}/bin/imlib2-config
BUILDLINK_CONFIG_WRAPPER.imlib2=	${BUILDLINK_DIR}/bin/imlib2-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
IMLIB2_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.imlib2}
CONFIGURE_ENV+=		IMLIB2_CONFIG="${IMLIB2_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.imlib2}
imlib2-buildlink: _BUILDLINK_USE
imlib2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# IMLIB2_BUILDLINK_MK
