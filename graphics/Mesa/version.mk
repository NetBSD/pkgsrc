# $NetBSD: version.mk,v 1.1 2002/11/20 22:13:21 jlam Exp $
#
# This file computes the version number of the Mesa distributed with
# XFree86 and stores it in ${_MESA_VERSION}.
#
# Note: This file should only be used by the Mesa-related packages.

.if !defined(MESA_VERSION_MK)
MESA_VERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

_GL_GLEXT_H=		${X11BASE}/include/GL/glext.h
_MESA_GL_VERSIONS=	1.2 1.3 1.4
.for _glvers_ in ${_MESA_GL_VERSIONS}
_MESA_GL_VERSION_${_glvers_}!= \
	if ${EGREP} -q "\#define[ 	]*GL_VERSION_${_glvers_:S/./_/}[ 	]*1" ${_GL_GLEXT_H}; then \
		${ECHO} YES;						\
	else								\
		${ECHO} NO;						\
	fi
.endfor
#
# According to the Mesa documentation, for stable releases:
#
#	Mesa-5.0 implements OpenGL 1.4,
#	Mesa-4.0.4 implements OpenGL 1.3
#	Mesa-3.4.2 implements OpenGL 1.2.
#
.if ${_MESA_GL_VERSION_1.4} == "YES"
_MESA_VERSION?=		5.0
.elif ${_MESA_GL_VERSION_1.3} == "YES"
_MESA_VERSION?=		4.0.4
.elif ${_MESA_GL_VERSION_1.2} == "YES"
_MESA_VERSION?=		3.4.2
.else
_MESA_VERSION?=		0
.endif

.endif	# MESA_VERSION_MK
