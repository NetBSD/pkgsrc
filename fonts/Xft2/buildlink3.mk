# $NetBSD: buildlink3.mk,v 1.6 2004/02/17 16:48:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFT2_BUILDLINK3_MK:=	${XFT2_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(XFT2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		Xft2
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1
BUILDLINK_PKGSRCDIR.Xft2?=	../../fonts/Xft2
.endif	# XFT2_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.Xft2?=	NO

_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.Xft2)
BUILDLINK_IS_BUILTIN.Xft2=	NO
.  if exists(${_X11_TMPL})
_IS_BUILTIN.Xft2!=							\
	if ${GREP} -q BuildXftLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.Xft2= ${_IS_BUILTIN.Xft2}
.    if !empty(BUILDLINK_CHECK_BUILTIN.Xft2:M[nN][oO]) && \
        !empty(_IS_BUILTIN.Xft2:M[yY][eE][sS])
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
.      if !defined(_XF86_VERSION)
_X11_CONFIG_VERSION_DEF=	${X11BASE}/lib/X11/config/version.def
.        if !exists(${_X11_CONFIG_VERSION_DEF})
_XF86_VERSION=	3.3
.        else
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
_XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}
.          else
_XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}.${_XF86_TEENY}
.          endif
.        endif
.      endif
.      for _xrender_version_ in ${_XFT2_VERSIONS}
.        for _pattern_ in ${_XFT2_${_xrender_version_}}
.          if !empty(_XF86_VERSION:M${_pattern_})
_XFT2_VERSION?=	${_xrender_version_}
.          endif
.        endfor
.      endfor
_XFT2_VERSION?=	0.0
_XFT2_PKG=	Xft2-${_XFT2_VERSION}

BUILDLINK_IS_BUILTIN.Xft2?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.Xft2}
.        if !empty(BUILDLINK_IS_BUILTIN.Xft2:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.Xft2!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_XFT2_PKG}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.Xft2=${BUILDLINK_IS_BUILTIN.Xft2}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.Xft2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xft2=	YES
.else
BUILDLINK_USE_BUILTIN.Xft2=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.Xft2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xft2=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xft2=	NO
.endif
.if !empty(PREFER_NATIVE:MXft2) && \
    !empty(BUILDLINK_IS_BUILTIN.Xft2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xft2=	YES
.endif
.if !empty(PREFER_PKGSRC:MXft2)
BUILDLINK_USE_BUILTIN.Xft2=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.Xft2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xft2=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.Xft2:M[nN][oO])
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1nb1
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		Xft2
.  endif
.endif

.if !empty(XFT2_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.Xft2:M[yY][eE][sS])
BUILDLINK_PREFIX.Xft2=	${X11BASE}
BUILDLINK_FILES.Xft2+=	lib/pkgconfig/xft.pc
.  endif
USE_X11=	yes
.  if !empty(BUILDLINK_CHECK_BUILTIN.Xft2:M[nN][oO])
.    include "../../fonts/fontconfig/buildlink3.mk"
.    include "../../x11/Xrender/buildlink3.mk"
.  endif
.endif	# XFT2_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
