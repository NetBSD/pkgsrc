# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:31 jlam Exp $

_FREETYPE2_FREETYPE_H=	${X11BASE}/include/freetype2/freetype/freetype.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.freetype2)
IS_BUILTIN.freetype2=	no
.  if exists(${_FREETYPE2_FREETYPE_H}) && exists(${_X11_TMPL})
IS_BUILTIN.freetype2!=							\
	if ${GREP} -q BuildFreetype2Library ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.freetype2:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in freetype2 distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_FREETYPE2_MAJOR!=	\
	${AWK} '/\#define[ 	]*FREETYPE_MAJOR/ { print $$3 }' ${_FREETYPE2_FREETYPE_H}
_FREETYPE2_MINOR!=	\
	${AWK} '/\#define[ 	]*FREETYPE_MINOR/ { print "."$$3 }' ${_FREETYPE2_FREETYPE_H}
_FREETYPE2_PATCH!=	\
	${AWK} 'BEGIN { patch=0; } /\#define[ 	]*FREETYPE_PATCH/ { patch=$$3; } END { print "."patch; }' ${_FREETYPE2_FREETYPE_H}
_FREETYPE2_VERSION=	${_FREETYPE2_MAJOR}${_FREETYPE2_MINOR}${_FREETYPE2_PATCH}
BUILTIN_PKG.freetype2=	freetype2-${_FREETYPE2_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.freetype2
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.freetype2
.endif	# IS_BUILTIN.freetype2

.if !defined(USE_BUILTIN.freetype2)
USE_BUILTIN.freetype2?=	${IS_BUILTIN.freetype2}

.  if defined(BUILTIN_PKG.freetype2)
USE_BUILTIN.freetype2=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.freetype2}
.      if !empty(USE_BUILTIN.freetype2:M[yY][eE][sS])
USE_BUILTIN.freetype2!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.freetype2}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.freetype2

CHECK_BUILTIN.freetype2?=	no
.if !empty(CHECK_BUILTIN.freetype2:M[nN][oO])

.if !empty(USE_BUILTIN.freetype2:M[nN][oO])
BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.3
.endif

.if !empty(USE_BUILTIN.freetype2:M[yY][eE][sS])
BUILDLINK_PREFIX.freetype2=	${X11BASE}
USE_X11=			yes
.endif

.endif	# CHECK_BUILTIN.freetype2
