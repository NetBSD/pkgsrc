# $NetBSD: builtin.mk,v 1.3 2004/03/30 17:04:06 jlam Exp $

_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.Xft2)
IS_BUILTIN.Xft2=	no
.  if exists(${_X11_TMPL})
IS_BUILTIN.Xft2!=							\
	if ${GREP} -q BuildXftLibrary ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.Xft2:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in Xft2 distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
# Xft2 doesn't provide a method of discovering the version number of
# the software.  Match up Xft2 versions with XFree86 versions for an
# approximate determination of the Xft2 version.
#
_XFT2_VERSIONS=	2.1.2  2.1.1  2.1.0
_XFT2_2.1.0=	4.2.99.* 4.3 4.3.[0-9] 4.3.[0-9].* 4.3.[1-8][0-9]* 4.3.9[0-8]*
.      if !defined(XF86_VERSION)
_X11_CONFIG_VERSION_DEF=	${X11BASE}/lib/X11/config/version.def
XF86_VERSION=	3.3
.        if exists(${_X11_CONFIG_VERSION_DEF})
_XF86_MAJOR!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_MAJOR/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_MINOR!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_MINOR/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_PATCH!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_PATCH/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_SNAP!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_SNAP/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_TEENY=	${_XF86_PATCH}.${_XF86_SNAP}
.          if !empty(_XF86_TEENY:M0.0)
XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}
.          else
XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}.${_XF86_TEENY}
.          endif
.        endif
BUILDLINK_VARS+=	XF86_VERSION
.      endif
.      for _xrender_version_ in ${_XFT2_VERSIONS}
.        for _pattern_ in ${_XFT2_${_xrender_version_}}
.          if !empty(XF86_VERSION:M${_pattern_})
_XFT2_VERSION?=	${_xrender_version_}
.          endif
.        endfor
.      endfor
_XFT2_VERSION?=		0.0
BUILTIN_PKG.Xft2=	Xft2-${_XFT2_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.Xft2
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.Xft2
.endif	# IS_BUILTIN.Xft2

.if defined(USE_BUILTIN.fontconfig) && !empty(USE_BUILTIN.fontconfig:M[nN][oO])
USE_BUILTIN.Xft2=	no
.endif
.if defined(USE_BUILTIN.Xrender) && !empty(USE_BUILTIN.Xrender:M[nN][oO])
USE_BUILTIN.Xft2=	no
.endif

.if !defined(USE_BUILTIN.Xft2)
USE_BUILTIN.Xft2?=	${IS_BUILTIN.Xft2}

.  if defined(BUILTIN_PKG.Xft2)
USE_BUILTIN.Xft2=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.Xft2}
.      if !empty(USE_BUILTIN.Xft2:M[yY][eE][sS])
USE_BUILTIN.Xft2!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.Xft2}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.Xft2

CHECK_BUILTIN.Xft2?=	no
.if !empty(CHECK_BUILTIN.Xft2:M[nN][oO])

.if !empty(USE_BUILTIN.Xft2:M[nN][oO])
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1nb1
.endif

.if !empty(USE_BUILTIN.Xft2:M[yY][eE][sS])
BUILDLINK_PREFIX.Xft2=	${X11BASE}
BUILDLINK_FILES.Xft2+=	lib/pkgconfig/xft.pc

USE_BUILTIN.Xrender=	yes
USE_BUILTIN.fontconfig=	yes
.endif

.endif	# CHECK_BUILTIN.Xft2
