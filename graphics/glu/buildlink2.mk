# $NetBSD: buildlink2.mk,v 1.7 2002/11/20 22:13:22 jlam Exp $

.if !defined(GLU_BUILDLINK2_MK)
GLU_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

MESA_REQD?=			3.4.2
BUILDLINK_DEPENDS.glu?=		glu>=${MESA_REQD}
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu

# Check if we got libGLU distributed with XFree86 4.x or if we need to
# depend on the glu package.
#
_REQUIRE_BUILTIN_GLU?=	NO

_GL_GLU_H=		${X11BASE}/include/GL/glu.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl
.if exists(${_GL_GLU_H}) && exists(${_X11_TMPL})
_IS_BUILTIN_GLU!=	${EGREP} -c BuildGLULibrary ${_X11_TMPL} || ${TRUE}
.else
_IS_BUILTIN_GLU=	0
.endif

.if !empty(_REQUIRE_BUILTIN_GLU:M[yY][eE][sS])
_NEED_GLU=		NO
.else
.  if ${_IS_BUILTIN_GLU} == "0"
_NEED_GLU=		YES
.  else
#
# Create an appropriate package name for the built-in Mesa/GLU distributed
# with XFree86 4.x.  This package name can be used to check against
# BUILDLINK_DEPENDS.glu to see if we need to install the pkgsrc Mesa/GLU
# or if the built-in one is sufficient.
#
.    include "../../graphics/Mesa/version.mk"
_GLU_PKG=		glu-${_MESA_VERSION}
_GLU_DEPENDS=		${BUILDLINK_DEPENDS.glu}
_NEED_GLU!= \
	if ${PKG_ADMIN} pmatch '${_GLU_DEPENDS}' ${_GLU_PKG}; then	\
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
.endif

.if ${_NEED_GLU} == "YES"
BUILDLINK_PACKAGES+=		glu
EVAL_PREFIX+=			BUILDLINK_PREFIX.glu=glu
BUILDLINK_PREFIX.glu_DEFAULT=	${X11PREFIX}
.else
BUILDLINK_PREFIX.glu=		${X11BASE}
.endif

BUILDLINK_FILES.glu=	include/GL/glu.h
BUILDLINK_FILES.glu+=	include/GL/glu_mangle.h
BUILDLINK_FILES.glu+=	lib/libGLU.*

USE_X11=		# defined

.include "../../graphics/MesaLib/buildlink2.mk"

BUILDLINK_TARGETS+=	glu-buildlink

glu-buildlink: _BUILDLINK_USE

.endif	# GLU_BUILDLINK2_MK
