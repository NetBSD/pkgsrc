# $NetBSD: builtin.mk,v 1.3 2004/04/24 21:20:56 snj Exp $

.include "../../mk/bsd.prefs.mk"

_X11_XPM_H=	${X11BASE}/include/X11/xpm.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.xpm)
IS_BUILTIN.xpm=	no
.  if exists(${_X11_XPM_H})
.    if !empty(X11BASE:M*openwin)
IS_BUILTIN.xpm!=							\
	if /usr/sbin/pkgchk -l SUNWxwinc | ${GREP} -q xpm.h; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    elif ${OPSYS} == "IRIX"
IS_BUILTIN.xpm=	yes
.    elif exists(${_X11_TMPL})
IS_BUILTIN.xpm!=							\
	if ${GREP} -q NormalLibXpm ${_X11_TMPL}; then			\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    else
IS_BUILTIN.xpm=	no
.    endif
.  endif
.  if !empty(IS_BUILTIN.xpm:M[yY][eE][sS])
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
_XPM_VERSION=		${_XPM_MAJOR}${_XPM_MINOR}${_XPM_PATCH}
BUILTIN_PKG.xpm=	xpm-${_XPM_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.xpm
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.xpm
.endif	# IS_BUILTIN.xpm

.if !defined(USE_BUILTIN.xpm)
USE_BUILTIN.xpm?=	${IS_BUILTIN.xpm}

.  if defined(BUILTIN_PKG.xpm)
USE_BUILTIN.xpm=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.xpm}
.      if !empty(USE_BUILTIN.xpm:M[yY][eE][sS])
USE_BUILTIN.xpm!=							\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.xpm}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.xpm

.if !empty(USE_BUILTIN.xpm:M[yY][eE][sS])
BUILDLINK_PREFIX.xpm=	${X11BASE}
.endif
