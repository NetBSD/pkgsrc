# $NetBSD: buildlink.mk,v 1.1 2001/06/16 19:23:19 jlam Exp $
#
# This Makefile fragment is included by packages that use xpm.
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(XPM_BUILDLINK_MK)
XPM_BUILDLINK_MK=	# defined

USE_XPM=		# defined

# We double-list because we're not sure if the files are in ${X11BASE}
# or in ${LOCALBASE}.

BUILDLINK_PREFIX.xpm-1=	${X11BASE}
BUILDLINK_FILES.xpm-1=	include/X11/X11/xpm.h	# for OpenWindows
BUILDLINK_FILES.xpm-1+=	include/X11/xpm.h
BUILDLINK_FILES.xpm-1+=	lib/libXpm.*

BUILDLINK_TARGETS.xpm=	xpm-1-buildlink

BUILDLINK_PREFIX.xpm-2=	${LOCALBASE}
BUILDLINK_FILES.xpm-2=	include/X11/X11/xpm.h	# for OpenWindows
BUILDLINK_FILES.xpm-2+=	include/X11/xpm.h
BUILDLINK_FILES.xpm-2+=	lib/libXpm.*

BUILDLINK_TARGETS.xpm+=	xpm-2-buildlink

BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.xpm}

pre-configure: ${BUILDLINK_TARGETS.xpm}
xpm-1-buildlink: _BUILDLINK_USE
xpm-2-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# XPM_BUILDLINK_MK
