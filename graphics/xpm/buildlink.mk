# $NetBSD: buildlink.mk,v 1.11 2002/06/26 05:40:34 jlam Exp $
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

# Check if we got Xpm distributed with XFree86 4.x or if we need to
# depend on the Xpm package.
#
_REQUIRE_BUILTIN_XPM?=	NO
.if exists(${X11BASE}/include/X11/xpm.h) && \
    exists(${X11BASE}/lib/X11/config/X11.tmpl)
_IS_BUILTIN_XPM!=	${EGREP} -c NormalLibXpm ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_XPM=	0
.endif
.if (${_IS_BUILTIN_XPM} == "0") && (${_REQUIRE_BUILTIN_XPM} == "NO")
_NEED_XPM=		YES
.else
_NEED_XPM=		NO
.endif

.if ${_NEED_XPM} == "YES"
DEPENDS+=		${BUILDLINK_DEPENDS.xpm}:../../graphics/xpm
EVAL_PREFIX+=		BUILDLINK_PREFIX.xpm=xpm
BUILDLINK_PREFIX.xpm_DEFAULT=	${X11PREFIX}
.else
BUILDLINK_PREFIX.xpm=	${X11BASE}
.endif

BUILDLINK_FILES.xpm+=	include/X11/xpm.h
BUILDLINK_FILES.xpm+=	lib/libXpm.*

BUILDLINK_TARGETS.xpm=	xpm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.xpm}

pre-configure: ${BUILDLINK_TARGETS.xpm}
xpm-buildlink: _BUILDLINK_USE

.endif	# XPM_BUILDLINK_MK
