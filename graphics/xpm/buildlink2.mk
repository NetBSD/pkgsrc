# $NetBSD: buildlink2.mk,v 1.3 2002/09/01 15:13:43 tron Exp $

.if !defined(XPM_BUILDLINK2_MK)
XPM_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.xpm?=		xpm-3.4k
BUILDLINK_PKGSRCDIR.xpm?=	../../graphics/xpm

# Check if we got Xpm distributed with XFree86 4.x or Solaris 9 or if we need
# to depend on the Xpm package.
#
_REQUIRE_BUILTIN_XPM?=	NO
.if (${OPSYS} != SunOS)
.if exists(${X11BASE}/include/X11/xpm.h) && \
    exists(${X11BASE}/lib/X11/config/X11.tmpl)
_IS_BUILTIN_XPM!=	${EGREP} -c NormalLibXpm ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_XPM=	0
.endif
.else
_IS_BUILTIN_XPM!=	(/usr/sbin/pkgchk -l SUNWxwinc | ${EGREP} -c xpm.h) || ${TRUE}
.endif
.if (${_IS_BUILTIN_XPM} == "0") && (${_REQUIRE_BUILTIN_XPM} == "NO")
_NEED_XPM=		YES
.else
_NEED_XPM=		NO
.endif

.if ${_NEED_XPM} == "YES"
BUILDLINK_PACKAGES+=	xpm
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
