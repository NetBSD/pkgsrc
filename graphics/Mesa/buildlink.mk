# $NetBSD: buildlink.mk,v 1.4 2001/06/11 01:59:36 jlam Exp $
#
# This Makefile fragment is included by packages that use Mesa.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define MESA_REQD to the version of Mesa desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MESA_BUILDLINK_MK)
MESA_BUILDLINK_MK=	# defined

MESA_REQD?=		3.2.1

# We double-list because we're not sure if the files are in ${X11BASE}
# or in ${LOCALBASE}.

BUILDLINK_PREFIX.Mesa-1=	${X11BASE}
BUILDLINK_FILES.Mesa-1=		include/GL/*
BUILDLINK_FILES.Mesa-1+=	lib/libGL.*
BUILDLINK_FILES.Mesa-1+=	lib/libGLU.*
BUILDLINK_FILES.Mesa-1+=	lib/libglut.*

BUILDLINK_TARGETS.Mesa=		Mesa-1-buildlink

BUILDLINK_PREFIX.Mesa-2=	${LOCALBASE}
BUILDLINK_FILES.Mesa-2=		include/GL/*
BUILDLINK_FILES.Mesa-2+=	lib/libGL.*
BUILDLINK_FILES.Mesa-2+=	lib/libGLU.*
BUILDLINK_FILES.Mesa-2+=	lib/libglut.*

BUILDLINK_TARGETS.Mesa+=	Mesa-2-buildlink

BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.Mesa}

pre-configure: ${BUILDLINK_TARGETS.Mesa}
Mesa-1-buildlink: _BUILDLINK_USE
Mesa-2-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# MESA_BUILDLINK_MK
