# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:11 jlam Exp $
#
# This Makefile fragment is included by packages that use glu.
#
# To use this Makefile fragment, simply include this Makefile fragment in the
# package Makefile.

.if !defined(GLU_BUILDLINK2_MK)
GLU_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.glu?=	glu>=3.4.2

# Check if we got libGLU distributed with XFree86 4.x or if we need to
# depend on the glu package.
#
.if exists(${X11BASE}/include/GL/glu.h)
_IS_BUILTIN_GLU!=	${EGREP} -c BuildGLULibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_GLU=	0
.endif
.if ${_IS_BUILTIN_GLU} == "0"
_NEED_GLU=		YES
.else
_NEED_GLU=		NO
.endif

.if ${_NEED_GLU} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.glu}:../../graphics/glu
EVAL_PREFIX+=	BUILDLINK_PREFIX.glu=glu
BUILDLINK_PREFIX.glu_DEFAULT=	${X11PREFIX}
.else
BUILDLINK_PREFIX.glu=	${X11BASE}
.endif

BUILDLINK_FILES.glu=	include/GL/glu.h
BUILDLINK_FILES.glu+=	include/GL/glu_mangle.h
BUILDLINK_FILES.glu+=	lib/libGLU.*

BUILDLINK_TARGETS+=	glu-buildlink

glu-buildlink: _BUILDLINK_USE

.endif	# GLU_BUILDLINK2_MK
