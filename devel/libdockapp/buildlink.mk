# $NetBSD: buildlink.mk,v 1.5 2001/07/27 13:33:23 jlam Exp $
#
# This Makefile fragment is included by packages that use libdockapp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libdockapp to the dependency pattern
#     for the version of libdockapp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBDOCKAPP_BUILDLINK_MK)
LIBDOCKAPP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libdockapp?=	libdockapp>=0.4.0
DEPENDS+=	${BUILDLINK_DEPENDS.libdockapp}:../../devel/libdockapp

EVAL_PREFIX+=			BUILDLINK_PREFIX.libdockapp=libdockapp
BUILDLINK_PREFIX.libdockapp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libdockapp=	include/dockapp.h
BUILDLINK_FILES.libdockapp+=	lib/libdockapp.*

.include "../../graphics/xpm/buildlink.mk"

BUILDLINK_TARGETS.libdockapp=	libdockapp-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libdockapp}

pre-configure: ${BUILDLINK_TARGETS.libdockapp}
libdockapp-buildlink: _BUILDLINK_USE

.endif	# LIBDOCKAPP_BUILDLINK_MK
