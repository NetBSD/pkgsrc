# $NetBSD: builtin.mk,v 1.4 2004/03/29 05:43:30 jlam Exp $

_GL_GLX_H=	${X11BASE}/include/GL/glx.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.include "../../graphics/Mesa/version.mk"
BUILDLINK_DEPENDS.MesaLib+=	MesaLib>=${_MESA_REQD}

.if !defined(IS_BUILTIN.MesaLib)
IS_BUILTIN.MesaLib=	no
.  if exists(${_GL_GLX_H}) && exists(${_X11_TMPL})
IS_BUILTIN.MesaLib!=							\
	if ${GREP} -q BuildGLXLibrary ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.MesaLib:M[yY][eE][sS])
#
# _MESA_VERSION is defined by Mesa/version.mk to be the version of the
# Mesa software distributed with the built-in XFree86.
#
BUILTIN_PKG.MesaLib=	MesaLib-${_MESA_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.MesaLib
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.MesaLib
.endif	# IS_BUILTIN.MesaLib

.if !defined(USE_BUILTIN.MesaLib)
USE_BUILTIN.MesaLib?=	${IS_BUILTIN.MesaLib}

.  if defined(BUILTIN_PKG.MesaLib)
USE_BUILTIN.MesaLib=		yes
.    for _depend_ in ${BUILDLINK_DEPENDS.MesaLib}
.      if !empty(USE_BUILTIN.MesaLib:M[yY][eE][sS])
USE_BUILTIN.MesaLib!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.MesaLib}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.MesaLib

CHECK_BUILTIN.MesaLib?=	no
.if !empty(CHECK_BUILTIN.MesaLib:M[nN][oO])

.if !empty(USE_BUILTIN.MesaLib:M[nN][oO])
BUILDLINK_DEPENDS.MesaLib+=	MesaLib>=6.0
.endif

.if !empty(USE_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_PREFIX.MesaLib=	${X11BASE}
USE_X11=			yes
_MESA_REQD=			${_MESA_VERSION}
.endif

.endif	# CHECK_BUILTIN.MesaLib
