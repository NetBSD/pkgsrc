# $NetBSD: buildlink.mk,v 1.1.1.1 2002/03/24 20:27:12 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use glib2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.glib2 to the dependency pattern
#     for the version of glib2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GLIB2_BUILDLINK_MK)
GLIB2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.glib2?=	glib2>=2.0.0
DEPENDS+=	${BUILDLINK_DEPENDS.glib2}:../../devel/glib2

EVAL_PREFIX+=		BUILDLINK_PREFIX.glib2=glib2
BUILDLINK_PREFIX.glib2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.glib2=	include/glib/glib-2.0/*/*
BUILDLINK_FILES.glib2+=	include/glib/glib-2.0/*
BUILDLINK_FILES.glib2+=	lib/glib-2.0/*/*
BUILDLINK_FILES.glib2+=	lib/libglib-2.0.*
BUILDLINK_FILES.glib2+=	lib/libgmodule-2.0.*
BUILDLINK_FILES.glib2+=	lib/libgobject-2.0.*
BUILDLINK_FILES.glib2+=	lib/libgthread-2.0.*

.include "../../devel/pkgconfig/buildlink.mk"

USE_PTHREAD=	native pth

.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink.mk"

BUILDLINK_TARGETS.glib2=	glib2-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.glib2}
BUILDLINK_TARGETS+=		${BUILDLINK_PKG_CONFIG}

pre-configure: ${BUILDLINK_TARGETS}
glib2-buildlink: _BUILDLINK_USE

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.endif	# GLIB2_BUILDLINK_MK
