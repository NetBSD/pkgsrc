# $NetBSD: builtin.mk,v 1.1 2004/03/10 17:57:14 jlam Exp $

_GL_GLU_H=	${X11BASE}/include/GL/glu.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.glu)
IS_BUILTIN.glu=	no
.  if exists(${_GL_GLU_H}) && exists(${_X11_TMPL})
IS_BUILTIN.glu!=							\
	if ${GREP} -q BuildGLULibrary ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.glu:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in Mesa/GLU distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
.      include "../../graphics/Mesa/version.mk"
BUILTIN_PKG.glu=	glu-${_MESA_VERSION}
MAKEFLAGS+=		BUILTIN_PKG.glu=${BUILTIN_PKG.glu}
.    endif
.  endif
MAKEFLAGS+=	IS_BUILTIN.glu=${IS_BUILTIN.glu}
.endif

CHECK_BUILTIN.glu?=	no
.if !empty(CHECK_BUILTIN.glu:M[yY][eE][sS])
USE_BUILTIN.glu=	yes
.endif

.if !defined(USE_BUILTIN.glu)
USE_BUILTIN.glu?=	${IS_BUILTIN.glu}

.  if defined(BUILTIN_PKG.glu)
USE_BUILTIN.glu=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.glu}
.      if !empty(USE_BUILTIN.glu:M[yY][eE][sS])
USE_BUILTIN.glu!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.glu}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.glu

.if !empty(USE_BUILTIN.glu:M[nN][oO])
BUILDLINK_DEPENDS.glu+=	glu>=6.0
.endif

.if !empty(USE_BUILTIN.glu:M[yY][eE][sS])
BUILDLINK_PREFIX.glu=	${X11BASE}
USE_X11=		yes
_MESA_REQD=		${_MESA_VERSION}
.endif
