# $NetBSD: buildlink.mk,v 1.4 2001/07/02 08:05:06 jlam Exp $
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

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.xpm?=	xpm-3.4k
CHECK_XPM=		# defined

.include "../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_XPM} == "NO"
DEPENDS+=		${BUILDLINK_DEPENDS.xpm}:../../graphics/xpm
BUILDLINK_PREFIX.xpm=	${X11PREFIX}
.else
BUILDLINK_PREFIX.xpm=	${X11BASE}
.endif

BUILDLINK_FILES.xpm=	include/X11/X11/xpm.h		# for OpenWindows
BUILDLINK_FILES.xpm+=	include/X11/xpm.h
BUILDLINK_FILES.xpm+=	lib/libXpm.*

BUILDLINK_TARGETS.xpm=	xpm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.xpm}

pre-configure: ${BUILDLINK_TARGETS.xpm}
xpm-buildlink: _BUILDLINK_USE

.endif	# XPM_BUILDLINK_MK
