# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:35 jlam Exp $

_EXPAT_H=	${X11BASE}/include/expat.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.expat)
IS_BUILTIN.expat=	no
.  if exists(${_X11_TMPL}) && exists(${_EXPAT_H})
IS_BUILTIN.expat!=							\
	if ${GREP} -q BuildExpatLibrary ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.expat:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in expat distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_EXPAT_MAJOR!=	\
	${AWK} '/\#define[ 	]*XML_MAJOR_VERSION/ { print $$3 }'	\
		${_EXPAT_H}
_EXPAT_MINOR!=	\
	${AWK} '/\#define[ 	]*XML_MINOR_VERSION/ { print $$3 }'	\
		${_EXPAT_H}
_EXPAT_MICRO!=	\
	${AWK} '/\#define[ 	]*XML_MICRO_VERSION/ { print $$3 }'	\
		${_EXPAT_H}
_EXPAT_VERSION=	${_EXPAT_MAJOR}.${_EXPAT_MINOR}.${_EXPAT_MICRO}
BUILTIN_PKG.expat=	expat-${_EXPAT_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.expat
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.expat
.endif	# IS_BUILTIN.expat

.if !defined(USE_BUILTIN.expat)
USE_BUILTIN.expat?=	${IS_BUILTIN.expat}

.  if defined(BUILTIN_PKG.expat)
USE_BUILTIN.expat=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.expat}
.      if !empty(USE_BUILTIN.expat:M[yY][eE][sS])
USE_BUILTIN.expat!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.expat}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.expat

CHECK_BUILTIN.expat?=	no
.if !empty(CHECK_BUILTIN.expat:M[nN][oO])

.if !empty(USE_BUILTIN.expat:M[nN][oO])
BUILDLINK_DEPENDS.expat+=	expat>=1.95.4
.endif

.if !empty(USE_BUILTIN.expat:M[yY][eE][sS])
BUILDLINK_PREFIX.expat=		${X11BASE}
USE_X11=			yes
.endif

.endif	# CHECK_BUILTIN.expat
