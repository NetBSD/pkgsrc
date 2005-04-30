# $NetBSD: version.mk,v 1.10 2005/04/30 02:16:12 jlam Exp $
#
# This file computes the version number of the Mesa distributed with
# XFree86 and stores it in ${_MESA_VERSION}.
#
# NOTE: This file should only be used by the Mesa-related builtin.mk files.
#
.if !defined(MESA_VERSION_MK)
MESA_VERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

_GL_GL_H=		${X11BASE}/include/GL/gl.h
_MESA_GL_VERSIONS=	1.2 1.3 1.4 1.5
.for _glvers_ in ${_MESA_GL_VERSIONS}
.  if !defined(_MESA_GL_VERSION_${_glvers_})
_MESA_GL_VERSION_${_glvers_}?=	no
.    if exists(${_GL_GL_H})
_MESA_GL_VERSION_${_glvers_}!= \
	if ${GREP} "\#define[ 	]*GL_VERSION_${_glvers_:S/./_/}[ 	]*1" ${_GL_GL_H} >/dev/null 2>&1; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    endif
MAKEFLAGS+=	_MESA_GL_VERSION_${_glvers_}=${_MESA_GL_VERSION_${_glvers_}}
.  endif
.endfor
#
# According to the Mesa documentation, for stable releases:
#
#	Mesa-6.0 implements OpenGL 1.5,
#	Mesa-5.0 implements OpenGL 1.4,
#	Mesa-4.0.4 implements OpenGL 1.3,
#	Mesa-3.4.2 implements OpenGL 1.2.
#
.if !empty(_MESA_GL_VERSION_1.5:M[yY][eE][sS])
_MESA_VERSION?=		6.0
.elif !empty(_MESA_GL_VERSION_1.4:M[yY][eE][sS])
_MESA_VERSION?=		5.0
.elif !empty(_MESA_GL_VERSION_1.3:M[yY][eE][sS])
_MESA_VERSION?=		4.0.4
.elif !empty(_MESA_GL_VERSION_1.2:M[yY][eE][sS])
_MESA_VERSION?=		3.4.2
.else
_MESA_VERSION?=		0
.endif

MESA_REQD?=		3.4.2

# Distill the MESA_REQD list into a single _MESA_REQD value that is the
# highest version of Mesa required.
#
_MESA_STRICTEST_REQD?=	none
.  for _version_ in ${MESA_REQD}
.    for _pkg_ in Mesa-${_version_}
.      if ${_MESA_STRICTEST_REQD} == "none"
_MESA_PKG_SATISFIES_DEP=	yes
.        for _vers_ in ${MESA_REQD}
.          if !empty(_MESA_PKG_SATISFIES_DEP:M[yY][eE][sS])
_MESA_PKG_SATISFIES_DEP!=	\
	if ${PKG_ADMIN} pmatch 'Mesa>=${_vers_}' ${_pkg_}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.          endif
.        endfor
.        if !empty(_MESA_PKG_SATISFIES_DEP:M[yY][eE][sS])
_MESA_STRICTEST_REQD=	${_version_}
.        endif
.      endif
.    endfor
.  endfor
_MESA_REQD=	${_MESA_STRICTEST_REQD}

.endif	# MESA_VERSION_MK
