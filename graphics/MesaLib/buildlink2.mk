# $NetBSD: buildlink2.mk,v 1.7 2002/11/20 22:13:22 jlam Exp $

.if !defined(MESALIB_BUILDLINK2_MK)
MESALIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

MESA_REQD?=			3.4.2
BUILDLINK_DEPENDS.MesaLib?=	MesaLib>=${MESA_REQD}
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib

# Check if we got Mesa distributed with XFree86 4.x or if we need to
# depend on the Mesa package.
#
_REQUIRE_BUILTIN_MESALIB?=	NO

_GL_GLX_H=		${X11BASE}/include/GL/glx.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl
.if exists(${_GL_GLX_H}) && exists(${_X11_TMPL})
_IS_BUILTIN_MESALIB!=	${EGREP} -c BuildGLXLibrary ${_X11_TMPL} || ${TRUE}
.else
_IS_BUILTIN_MESALIB=	0
.endif

.if !empty(_REQUIRE_BUILTIN_MESALIB:M[yY][eE][sS])
_NEED_MESALIB=		NO
.else
.  if ${_IS_BUILTIN_MESALIB} == "0"
_NEED_MESALIB=		YES
.  else
#
# Create an appropriate package name for the built-in MesaLib distributed
# with XFree86 4.x.  This package name can be used to check against
# BUILDLINK_DEPENDS.MesaLib to see if we need to install the pkgsrc
# Mesa or if the built-in one is sufficient.
#
.    include "../../graphics/Mesa/version.mk"
_MESALIB_PKG=		MesaLib-${_MESA_VERSION}
_MESALIB_DEPENDS=	${BUILDLINK_DEPENDS.MesaLib}
_NEED_MESALIB!= \
	if ${PKG_ADMIN} pmatch '${_MESALIB_DEPENDS}' ${_MESALIB_PKG}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
.endif

.if ${_NEED_MESALIB} == "YES"
BUILDLINK_PACKAGES+=		MesaLib
EVAL_PREFIX+=			BUILDLINK_PREFIX.MesaLib=MesaLib
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

USE_X11=			# defined

BUILDLINK_TARGETS+=		MesaLib-buildlink

MesaLib-buildlink: _BUILDLINK_USE

.endif	# MESALIB_BUILDLINK2_MK
