# $NetBSD: buildlink.mk,v 1.13 2001/12/31 22:25:19 jlam Exp $
#
# This Makefile fragment is included by packages that use glib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.glib to the dependency pattern
#     for the version of glib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GLIB_BUILDLINK_MK)
GLIB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.glib?=	glib>=1.2.8
DEPENDS+=	${BUILDLINK_DEPENDS.glib}:../../devel/glib

EVAL_PREFIX+=		BUILDLINK_PREFIX.glib=glib
BUILDLINK_PREFIX.glib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.glib=	include/glib/*/*
BUILDLINK_FILES.glib+=	include/glib/*
BUILDLINK_FILES.glib+=	lib/glib/*/*
BUILDLINK_FILES.glib+=	lib/libglib.*
BUILDLINK_FILES.glib+=	lib/libgmodule.*
BUILDLINK_FILES.glib+=	lib/libgthread.*

USE_PTHREAD=	native pth

.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink.mk"

BUILDLINK_TARGETS.glib=		glib-buildlink
BUILDLINK_TARGETS.glib+=	glib-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.glib}

BUILDLINK_CONFIG.glib=		${BUILDLINK_PREFIX.glib}/bin/glib-config
BUILDLINK_CONFIG_WRAPPER.glib=	${BUILDLINK_DIR}/bin/glib-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.glib}|${BUILDLINK_CONFIG.glib}|g"

.if defined(USE_CONFIG_WRAPPER)
GLIB_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.glib}
CONFIGURE_ENV+=		GLIB_CONFIG="${GLIB_CONFIG}"
MAKE_ENV+=		GLIB_CONFIG="${GLIB_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.glib}
glib-buildlink: _BUILDLINK_USE
glib-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GLIB_BUILDLINK_MK
