# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:16 jlam Exp $
#
# This Makefile fragment is included by packages that use xpm.
#
# To use this Makefile fragment, simply include this Makefile fragment in the
# package Makefile.

.if !defined(XPM_BUILDLINK2_MK)
XPM_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.xpm?=	xpm-3.4k

# Check if we got Xpm distributed with XFree86 4.x or if we need to
# depend on the Xpm package.
#
.if exists(${X11BASE}/include/X11/xpm.h) && \
    exists(${X11BASE}/lib/X11/config/X11.tmpl)
_IS_BUILTIN_XPM!=	${EGREP} -c NormalLibXpm ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_XPM=	0
.endif
.if ${_IS_BUILTIN_XPM} == "0"
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

BUILDLINK_TARGETS+=	xpm-buildlink

xpm-buildlink: _BUILDLINK_USE

.endif	# XPM_BUILDLINK2_MK
