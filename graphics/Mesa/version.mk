# $NetBSD: version.mk,v 1.12 2005/06/20 22:13:10 jlam Exp $
#
# This file computes the version number of the Mesa distributed with
# XFree86 and stores it in ${BUILTIN_VERSION.Mesa}.
#
# NOTE: This file should only be used by the Mesa-related builtin.mk files.
#

BUILTIN_FIND_FILES_VAR:=	H_MESA
BUILTIN_FIND_FILES.H_MESA=	${X11BASE}/include/GL/gl.h
.include "../../mk/buildlink3/find-files.mk"

.if !defined(BUILTIN_VERSION.Mesa) && exists(${H_MESA})
#
# According to the Mesa documentation, for stable releases:
#
#	Mesa-6.0 implements OpenGL 1.5,
#	Mesa-5.0 implements OpenGL 1.4,
#	Mesa-4.0.4 implements OpenGL 1.3,
#	Mesa-3.4.2 implements OpenGL 1.2.
#
BUILTIN_VERSION.Mesa!=							\
	${AWK} '/\#define[ 	]*GL_VERSION_1_2/ { v = "3.4.2" }	\
		/\#define[ 	]*GL_VERSION_1_3/ { v = "4.0.4" }	\
		/\#define[ 	]*GL_VERSION_1_4/ { v = "5.0" }		\
		/\#define[ 	]*GL_VERSION_1_5/ { v = "6.0" }		\
		END { printf "%s\n", v }'				\
		${H_MESA}
.endif
MAKEVARS+=	BUILTIN_VERSION.Mesa
