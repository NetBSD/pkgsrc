# $NetBSD: buildlink3.mk,v 1.20 2004/02/12 01:59:38 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLU_BUILDLINK3_MK:=	${GLU_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(GLU_BUILDLINK3_MK:M+)
.  include "../../graphics/MesaLib/buildlink3.mk"

BUILDLINK_PACKAGES+=		glu
BUILDLINK_DEPENDS.glu+=		glu>=${_MESA_REQD}
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu
.endif	# GLU_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.glu?=	NO

_GL_GLU_H=	${X11BASE}/include/GL/glu.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.glu)
BUILDLINK_IS_BUILTIN.glu=	NO
.  if exists(${_GL_GLU_H}) && exists(${_X11_TMPL})
_IS_BUILTIN.glu!=							\
	if ${GREP} -q BuildGLULibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.glu=	${_IS_BUILTIN.glu}
.    if !empty(BUILDLINK_CHECK_BUILTIN.glu:M[nN][oO]) && \
        !empty(_IS_BUILTIN.glu:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in Mesa/GLU distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
.      include "../../graphics/Mesa/version.mk"
_GLU_PKG=	glu-${_MESA_VERSION}
BUILDLINK_IS_BUILTIN.glu?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.glu}
.        if !empty(BUILDLINK_IS_BUILTIN.glu:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.glu!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_GLU_PKG}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.glu=${BUILDLINK_IS_BUILTIN.glu}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.glu:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.glu=	YES
.else
BUILDLINK_USE_BUILTIN.glu=	NO
.endif

.if !empty(PREFER_PKGSRC:M[yY][eE][sS]) || \
    !empty(PREFER_PKGSRC:Mglu)
BUILDLINK_USE_BUILTIN.glu=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.glu:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.glu=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.glu:M[nN][oO])
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.glu+=	glu>=6.0
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glu
.  endif
.endif

.if !empty(GLU_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.glu:M[yY][eE][sS])
BUILDLINK_PREFIX.glu=	${X11BASE}
USE_X11=		yes
_MESA_REQD=		${_MESA_VERSION}
.  endif
.endif	# GLU_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
