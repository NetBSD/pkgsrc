# $NetBSD: buildlink2.mk,v 1.3 2002/09/01 11:49:42 tron Exp $

.if !defined(GLU_BUILDLINK2_MK)
GLU_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.glu?=		glu>=3.4.2
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu

# Check if we got libGLU distributed with XFree86 4.x or if we need to
# depend on the glu package.
#
_REQUIRE_BUILTIN_GLU?=	NO
.if (${OPSYS} != SunOS) && exists(${X11BASE}/include/GL/glu.h)
_IS_BUILTIN_GLU!=	${EGREP} -c BuildGLULibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_GLU=	0
.endif
.if (${_IS_BUILTIN_GLU} == "0") && (${_REQUIRE_BUILTIN_GLU} == "NO")
_NEED_GLU=		YES
.else
_NEED_GLU=		NO
.endif

.if ${_NEED_GLU} == "YES"
BUILDLINK_PACKAGES+=		glu
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
