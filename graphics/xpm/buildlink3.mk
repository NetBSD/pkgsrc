# $NetBSD: buildlink3.mk,v 1.8 2004/01/04 23:34:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XPM_BUILDLINK3_MK:=	${XPM_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(XPM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xpm?=		xpm>=3.4k
BUILDLINK_PKGSRCDIR.xpm?=	../../graphics/xpm
.endif	# XPM_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.xpm?=	NO

_X11_XPM_H=	${X11BASE}/include/X11/xpm.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.xpm)
BUILDLINK_IS_BUILTIN.xpm=	NO
.  if exists(${_X11_XPM_H})
.    if !empty(X11BASE:M*openwin)
BUILDLINK_IS_BUILTIN.xpm!=						\
	if /usr/sbin/pkgchk -l SUNWxwinc | ${GREP} -q xpm.h; then	\
		${ECHO} YES;						\
	else								\
		${ECHO} NO;						\
	fi
.    elif exists(${_X11_TMPL})
BUILDLINK_IS_BUILTIN.xpm!=						\
	if ${GREP} -q NormalLibXpm ${_X11_TMPL}; then			\
		${ECHO} YES;						\
	else								\
		${ECHO} NO;						\
	fi
.    else
BUILDLINK_IS_BUILTIN.xpm=	NO
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.xpm=${BUILDLINK_IS_BUILTIN.xpm}
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.xpm:M[yY][eE][sS])
_NEED_XPM=	NO
.endif

.if !defined(_NEED_XPM)
.  if !empty(BUILDLINK_IS_BUILTIN.xpm:M[nN][oO])
_NEED_XPM=	YES
.  else
#
# Create an appropriate package name for the built-in xpm distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_XPM_MAJOR!=	\
	${AWK} '/\#define[ 	]*XpmFormat/ { print $$3 }' ${_X11_XPM_H}
_XPM_MINOR!=	\
	${AWK} '/\#define[ 	]*XpmVersion/ { print "."$$3 }' ${_X11_XPM_H}
_XPM_PATCH!=	\
	${AWK} 'BEGIN { split("abcdefghijklmnopqrstuvwxyz", alpha, "") } /\#define[ 	]*XpmRevision/ { print alpha[$$3] }' ${_X11_XPM_H}
_XPM_VERSION=	${_XPM_MAJOR}${_XPM_MINOR}${_XPM_PATCH}
_XPM_PKG=	xpm-${_XPM_VERSION}
_XPM_DEPENDS=	${BUILDLINK_DEPENDS.xpm}
_NEED_XPM!=	\
	if ${PKG_ADMIN} pmatch '${_XPM_DEPENDS}' ${_XPM_PKG}; then	\
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
MAKEFLAGS+=	_NEED_XPM="${_NEED_XPM}"
.endif	# _NEED_XPM

.if ${_NEED_XPM} == "YES"
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xpm
.  endif
.endif

.if !empty(XPM_BUILDLINK3_MK:M+)
.  if ${_NEED_XPM} == "YES"
BUILDLINK_PACKAGES+=	xpm
.  else
BUILDLINK_PREFIX.xpm=	${X11BASE}
.  endif
.endif	# XPM_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
