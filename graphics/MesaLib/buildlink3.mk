# $NetBSD: buildlink3.mk,v 1.12 2004/01/24 01:53:00 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MESALIB_BUILDLINK3_MK:=	${MESALIB_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(MESALIB_BUILDLINK3_MK:M+)
MESA_REQD?=		3.4.2

BUILDLINK_PACKAGES+=		MesaLib
BUILDLINK_DEPENDS.MesaLib?=	MesaLib>=${MESA_REQD}
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib
.endif	# MESALIB_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.MesaLib?=	NO

_GL_GLX_H=	${X11BASE}/include/GL/glx.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.MesaLib)
BUILDLINK_IS_BUILTIN.MesaLib=	NO
.  if exists(${_GL_GLX_H}) && exists(${_X11_TMPL})
BUILDLINK_IS_BUILTIN.MesaLib!=						\
	if ${GREP} -q BuildGLXLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.MesaLib="${BUILDLINK_IS_BUILTIN.MesaLib}"
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.MesaLib=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.MesaLib)
.  if !empty(BUILDLINK_IS_BUILTIN.MesaLib:M[nN][oO])
BUILDLINK_USE_BUILTIN.MesaLib=	NO
.  else
#
# Create an appropriate package name for the built-in Mesa/GLX distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
.    include "../../graphics/Mesa/version.mk"
_MESALIB_PKG=		MesaLib-${_MESA_VERSION}
_MESALIB_DEPENDS=	${BUILDLINK_DEPENDS.MesaLib}
BUILDLINK_USE_BUILTIN.MesaLib!=	\
	if ${PKG_ADMIN} pmatch '${_MESALIB_DEPENDS}' ${_MESALIB_PKG}; then \
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
MAKEFLAGS+=	\
	BUILDLINK_USE_BUILTIN.MesaLib="${BUILDLINK_USE_BUILTIN.MesaLib}"
.endif	# BUILDLINK_USE_BUILTIN.MesaLib

.if !empty(BUILDLINK_USE_BUILTIN.MesaLib:M[nN][oO])
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.MesaLib=	MesaLib>=5.0
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		MesaLib
.  endif
.endif

.if !empty(MESALIB_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_PREFIX.MesaLib=	${X11BASE}
USE_X11=			yes
.  else
BUILDLINK_CPPFLAGS.MesaLib=	-DGLX_GLXEXT_LEGACY
.  endif
.endif	# MESALIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
