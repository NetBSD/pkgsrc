# $NetBSD: builtin.mk,v 1.3 2004/03/29 05:43:31 jlam Exp $

_GL_GLU_H=	${X11BASE}/include/GL/glu.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.include "../../graphics/Mesa/version.mk"
BUILDLINK_DEPENDS.glu+=	glu>=${_MESA_REQD}

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
# _MESA_VERSION is defined by Mesa/version.mk to be the version of the
# Mesa software distributed with the built-in XFree86.
#
BUILTIN_PKG.glu=	glu-${_MESA_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.glu
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.glu
.endif	# IS_BUILTIN.glu

.if defined(USE_BUILTIN.MesaLib) && !empty(USE_BUILTIN.MesaLib:M[nN][oO])
USE_BUILTIN.glu=	no
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

CHECK_BUILTIN.glu?=	no
.if !empty(CHECK_BUILTIN.glu:M[nN][oO])

.if !empty(USE_BUILTIN.glu:M[nN][oO])
BUILDLINK_DEPENDS.glu+=	glu>=6.0
.endif

.if !empty(USE_BUILTIN.glu:M[yY][eE][sS])
BUILDLINK_PREFIX.glu=	${X11BASE}
USE_X11=		yes
_MESA_REQD=		${_MESA_VERSION}
.endif

.endif	# CHECK_BUILTIN.glu
