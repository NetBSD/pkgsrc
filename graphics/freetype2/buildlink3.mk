# $NetBSD: buildlink3.mk,v 1.18 2004/02/12 02:35:06 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FREETYPE2_BUILDLINK3_MK:=	${FREETYPE2_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(FREETYPE2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		freetype2
BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.3
BUILDLINK_PKGSRCDIR.freetype2?=	../../graphics/freetype2
BUILDLINK_INCDIRS.freetype2?=	include/freetype2
.endif	# FREETYPE2_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.freetype2?=	NO

_FREETYPE2_FREETYPE_H=	${X11BASE}/include/freetype2/freetype/freetype.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.freetype2)
BUILDLINK_IS_BUILTIN.freetype2=	NO
.  if exists(${_FREETYPE2_FREETYPE_H}) && exists(${_X11_TMPL})
_IS_BUILTIN.freetype2!=							\
	if ${GREP} -q BuildFreetype2Library ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.freetype2=	${_IS_BUILTIN.freetype2}
.    if !empty(BUILDLINK_CHECK_BUILTIN.freetype2:M[nN][oO]) && \
        !empty(_IS_BUILTIN.freetype2:M[yY][eE][sS])
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
_FREETYPE2_PKG=		freetype2-${_FREETYPE2_VERSION}
BUILDLINK_IS_BUILTIN.freetype2?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.freetype2}
.        if !empty(BUILDLINK_IS_BUILTIN.freetype2:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.freetype2!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_FREETYPE2_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.freetype2=${BUILDLINK_IS_BUILTIN.freetype2}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.freetype2:M[yY][eE][sS]I)
BUILDLINK_USE_BUILTIN.freetype2=	YES
.else
BUILDLINK_USE_BUILTIN.freetype2=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.freetype2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.freetype2=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.freetype2=	NO
.endif
.if !empty(PREFER_NATIVE:Mfreetype2) && \
    !empty(BUILDLINK_IS_BUILTIN.freetype2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.freetype2=	YES
.endif
.if !empty(PREFER_PKGSRC:Mfreetype2)
BUILDLINK_USE_BUILTIN.freetype2=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.freetype2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.freetype2=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.freetype2:M[nN][oO])
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.3
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		freetype2
.  endif
.endif

.if !empty(FREETYPE2_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.freetype2:M[yY][eE][sS])
BUILDLINK_PREFIX.freetype2=	${X11BASE}
USE_X11=			yes
.  endif

FREETYPE_CONFIG?=	${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
CONFIGURE_ENV+=		FREETYPE_CONFIG="${FREETYPE_CONFIG}"
.endif	# FREETYPE2_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
