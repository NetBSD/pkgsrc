# $NetBSD: buildlink.mk,v 1.1.1.1 2002/07/12 16:22:58 wiz Exp $
#
# This Makefile fragment is included by packages that use libbonobo.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libbonobo to the dependency pattern
#     for the version of libbonobo desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBBONOBO_BUILDLINK_MK)
LIBBONOBO_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libbonobo?=	libbonobo>=2.0.0
DEPENDS+=	${BUILDLINK_DEPENDS.libbonobo}:../../devel/libbonobo

EVAL_PREFIX+=		BUILDLINK_PREFIX.libbonobo=libbonobo
BUILDLINK_PREFIX.libbonobo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libbonobo+=	include/libbonobo-2.0/bonobo/*
BUILDLINK_FILES.libbonobo+=	include/libbonobo-2.0/*
BUILDLINK_FILES.libbonobo+=	lib/bonobo/monikers/*
BUILDLINK_FILES.libbonobo+=	lib/bonobo/servers/*
BUILDLINK_FILES.libbonobo+=	lib/libbonobo-2.*
BUILDLINK_FILES.libbonobo+=	lib/orbit-2.0/Bonobo_module.*
BUILDLINK_FILES.libbonobo+=	lib/pkgconfig/libbonobo-2.0.pc
BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-2.0/*

.include "../../devel/pkgconfig/buildlink.mk"
.include "../../mk/bsd.prefs.mk"

BUILDLINK_TARGETS.libbonobo=	libbonobo-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libbonobo}
BUILDLINK_TARGETS+=		${BUILDLINK_PKG_CONFIG}

pre-configure: ${BUILDLINK_TARGETS}
libbonobo-buildlink: _BUILDLINK_USE

.include "../../devel/bonobo-activation/buildlink.mk"
.endif	# LIBBONOBO_BUILDLINK_MK
