# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:30 jlam Exp $

_FONTCONFIG_FONTCONFIG_H=	${X11BASE}/include/fontconfig/fontconfig.h
_X11_TMPL=			${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.fontconfig)
IS_BUILTIN.fontconfig=	no
.  if exists(${_FONTCONFIG_FONTCONFIG_H}) && exists(${_X11_TMPL})
IS_BUILTIN.fontconfig!=							\
	if ${GREP} -q BuildFontconfigLibrary ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.fontconfig:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in fontconfig distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_FONTCONFIG_MAJOR!=	\
	${AWK} '/\#define[ 	]*FC_MAJOR/ { print $$3 }'		\
		${_FONTCONFIG_FONTCONFIG_H}
_FONTCONFIG_MINOR!=	\
	${AWK} '/\#define[ 	]*FC_MINOR/ { print $$3 }'		\
		${_FONTCONFIG_FONTCONFIG_H}
_FONTCONFIG_REVISION!=	\
	${AWK} '/\#define[ 	]*FC_REVISION/ { print $$3 }'		\
		${_FONTCONFIG_FONTCONFIG_H}
_FONTCONFIG_VERSION=	\
	${_FONTCONFIG_MAJOR}.${_FONTCONFIG_MINOR}.${_FONTCONFIG_REVISION}
BUILTIN_PKG.fontconfig=	fontconfig-${_FONTCONFIG_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.fontconfig
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.fontconfig
.endif	# IS_BUILTIN.fontconfig

.if defined(USE_BUILTIN.zlib) && !empty(USE_BUILTIN.zlib:M[nN][oO])
USE_BUILTIN.fontconfig=	no
.endif
.if defined(USE_BUILTIN.freetype2) && !empty(USE_BUILTIN.freetype2:M[nN][oO])
USE_BUILTIN.fontconfig=	no
.endif
.if defined(USE_BUILTIN.expat) && !empty(USE_BUILTIN.expat:M[nN][oO])
USE_BUILTIN.fontconfig=	no
.endif

.if !defined(USE_BUILTIN.fontconfig)
USE_BUILTIN.fontconfig?=	${IS_BUILTIN.fontconfig}

.  if defined(BUILTIN_PKG.fontconfig)
USE_BUILTIN.fontconfig=		yes
.    for _depend_ in ${BUILDLINK_DEPENDS.fontconfig}
.      if !empty(USE_BUILTIN.fontconfig:M[yY][eE][sS])
USE_BUILTIN.fontconfig!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.fontconfig}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.fontconfig

CHECK_BUILTIN.fontconfig?=	no
.if !empty(CHECK_BUILTIN.fontconfig:M[nN][oO])

.if !empty(USE_BUILTIN.fontconfig:M[nN][oO])
BUILDLINK_DEPENDS.fontconfig+=	fontconfig>=2.1nb2
BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.3
.endif

.if !empty(USE_BUILTIN.fontconfig:M[yY][eE][sS])
BUILDLINK_PREFIX.fontconfig=	${X11BASE}
BUILDLINK_FILES.fontconfig+=	lib/pkgconfig/fontconfig.pc

USE_BUILTIN.expat=	yes
USE_BUILTIN.freetype2=	yes
USE_BUILTIN.zlib=	yes
.endif

.endif	# CHECK_BUILTIN.fontconfig
