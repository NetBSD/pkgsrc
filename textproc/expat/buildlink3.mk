# $NetBSD: buildlink3.mk,v 1.7 2004/02/17 10:55:02 recht Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EXPAT_BUILDLINK3_MK:=	${EXPAT_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(EXPAT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		expat
BUILDLINK_DEPENDS.expat+=	expat>=1.95.4
BUILDLINK_PKGSRCDIR.expat?=	../../textproc/expat
.endif	# EXPAT_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.expat?=	NO

_EXPAT_H=	${X11BASE}/include/expat.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.expat)
BUILDLINK_IS_BUILTIN.expat=	NO
.  if exists(${_X11_TMPL}) && exists(${_X11_EXTENSIONS_EXPAT_H})
_IS_BUILTIN.expat!=							\
	if ${GREP} -q BuildExpatLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.expat=	${_IS_BUILTIN.expat}
.    if !empty(BUILDLINK_CHECK_BUILTIN.expat:M[nN][oO]) && \
        !empty(_IS_BUILTIN.expat:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in expat distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_EXPAT_MAJOR!=	\
	${AWK} '/\#define[ 	]*XML_MAJOR_REVISION/ { print $$3 }'	\
		${_EXPAT_H}
_EXPAT_MINOR!=	\
	${AWK} '/\#define[ 	]*XML_MINOR_REVISION/ { print $$3 }'	\
		${_EXPAT_H}
_EXPAT_MICRO!=	\
	${AWK} '/\#define[ 	]*XML_MICRO_REVISION/ { print $$3 }'	\
		${_EXPAT_H}
_EXPAT_VERSION=	${_EXPAT_MAJOR}.${_EXPAT_MINOR}.${_EXPAT_MICRO}
_EXPAT_PKG=		expat-${_EXPAT_VERSION}
BUILDLINK_IS_BUILTIN.expat?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.expat}
.        if !empty(BUILDLINK_IS_BUILTIN.expat:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.expat!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_EXPAT_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.expat=${BUILDLINK_IS_BUILTIN.expat}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.expat:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.expat=	YES
.else
BUILDLINK_USE_BUILTIN.expat=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.expat:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.expat=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.expat=	NO
.endif
.if !empty(PREFER_NATIVE:Mexpat) && \
    !empty(BUILDLINK_IS_BUILTIN.expat:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.expat=	YES
.endif
.if !empty(PREFER_PKGSRC:Mexpat)
BUILDLINK_USE_BUILTIN.expat=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.expat:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.expat=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.expat:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		expat
.  endif
.endif

.if !empty(EXPAT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.expat+=	expat>=1.95.4
.  if !empty(BUILDLINK_USE_BUILTIN.expat:M[yY][eE][sS])
BUILDLINK_PREFIX.expat=	${X11BASE}
.  endif
USE_X11=	yes
.endif	# EXPAT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
