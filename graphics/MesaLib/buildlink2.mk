# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:09 jlam Exp $
#
# This Makefile fragment is included by packages that use MesaLib.
#
# To use this Makefile fragment, simply include this Makefile fragment in the
# package Makefile.

.if !defined(MESALIB_BUILDLINK2_MK)
MESALIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.MesaLib?=	MesaLib>=3.4.2

# Check if we got Mesa distributed with XFree86 4.x or if we need to
# depend on the Mesa package.
#
.if exists(${X11BASE}/include/GL/glx.h)
_IS_BUILTIN_MESALIB!=	${EGREP} -c BuildGLXLibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_MESALIB=	0
.endif
.if ${_IS_BUILTIN_MESALIB} == "0"
_NEED_MESALIB=		YES
.else
_NEED_MESALIB=		NO
.endif

.if ${_NEED_MESALIB} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.MesaLib}:../../graphics/MesaLib
EVAL_PREFIX+=	BUILDLINK_PREFIX.MesaLib=MesaLib
BUILDLINK_PREFIX.MesaLib_DEFAULT=	${X11PREFIX}
.else
BUILDLINK_PREFIX.MesaLib=	${X11BASE}
.endif

BUILDLINK_FILES.MesaLib+=	include/GL/GL*.h
BUILDLINK_FILES.MesaLib+=	include/GL/gl.h
BUILDLINK_FILES.MesaLib+=	include/GL/glext.h
BUILDLINK_FILES.MesaLib+=	include/GL/gl_mangle.h
BUILDLINK_FILES.MesaLib+=	include/GL/glx*.h
BUILDLINK_FILES.MesaLib+=	include/GL/osmesa.h
BUILDLINK_FILES.MesaLib+=	include/GL/xmesa.h
BUILDLINK_FILES.MesaLib+=	include/GL/xmesa_x.h
BUILDLINK_FILES.MesaLib+=	include/GL/xmesa_xf86.h
BUILDLINK_FILES.MesaLib+=	lib/libGL.*

BUILDLINK_TARGETS+=		MesaLib-buildlink

MesaLib-buildlink: _BUILDLINK_USE

.endif	# MESALIB_BUILDLINK2_MK
