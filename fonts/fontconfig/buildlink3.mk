# $NetBSD: buildlink3.mk,v 1.5 2004/02/16 19:24:14 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FONTCONFIG_BUILDLINK3_MK:=	${FONTCONFIG_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(FONTCONFIG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			fontconfig
BUILDLINK_DEPENDS.fontconfig+=		fontconfig>=2.1nb1
BUILDLINK_PKGSRCDIR.fontconfig?=	../../x11/fontconfig
.endif	# FONTCONFIG_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.fontconfig?=	NO

_FONTCONFIG_FONTCONFIG_H=	${X11BASE}/include/fontconfig/fontconfig.h
_X11_TMPL=			${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.fontconfig)
BUILDLINK_IS_BUILTIN.fontconfig=	NO
.  if exists(${_FONTCONFIG_FONTCONFIG_H}) && exists(${_X11_TMPL})
_IS_BUILTIN.fontconfig!=						\
	if ${GREP} -q BuildFontconfigLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.fontconfig= ${_IS_BUILTIN.fontconfig}
.    if !empty(BUILDLINK_CHECK_BUILTIN.fontconfig:M[nN][oO]) && \
        !empty(_IS_BUILTIN.fontconfig:M[yY][eE][sS])
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
_FONTCONFIG_PKG=	fontconfig-${_FONTCONFIG_VERSION}

BUILDLINK_IS_BUILTIN.fontconfig?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.fontconfig}
.        if !empty(BUILDLINK_IS_BUILTIN.fontconfig:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.fontconfig!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_FONTCONFIG_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	\
	BUILDLINK_IS_BUILTIN.fontconfig=${BUILDLINK_IS_BUILTIN.fontconfig}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.fontconfig:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.fontconfig=	YES
.else
BUILDLINK_USE_BUILTIN.fontconfig=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.fontconfig:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.fontconfig=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.fontconfig=	NO
.endif
.if !empty(PREFER_NATIVE:Mfontconfig) && \
    !empty(BUILDLINK_IS_BUILTIN.fontconfig:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.fontconfig=	YES
.endif
.if !empty(PREFER_PKGSRC:Mfontconfig)
BUILDLINK_USE_BUILTIN.fontconfig=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.fontconfig:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.fontconfig=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.fontconfig:M[nN][oO])
BUILDLINK_DEPENDS.fontconfig+=	fontconfig>2.1nb2
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		fontconfig
.  endif
.endif

.if !empty(FONTCONFIG_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.fontconfig:M[yY][eE][sS])
BUILDLINK_PREFIX.fontconfig=	${X11BASE}
.  endif
USE_X11=	yes
BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.3

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../graphics/freetype2/buildlink3.mk"
.  include "../../textproc/expat/buildlink3.mk"
.endif	# FONTCONFIG_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
