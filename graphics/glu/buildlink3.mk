# $NetBSD: buildlink3.mk,v 1.4 2003/09/28 12:54:52 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+

.include "../../mk/bsd.prefs.mk"

MESA_REQD?=		3.4.2

BUILDLINK_DEPENDS.glu?=		glu>=${MESA_REQD}
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu

BUILDLINK_CHECK_BUILTIN.glu?=	NO

_GL_GLU_H=	${X11BASE}/include/GL/glu.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.glu)
BUILDLINK_IS_BUILTIN.glu=	NO
.  if exists(${_GL_GLU_H}) && exists(${_X11_TMPL})
BUILDLINK_IS_BUILTIN.glu!=						\
	if ${GREP} -q BuildGLULibrary ${_X11_TMPL}; then		\
		${ECHO} YES;						\
	else								\
		${ECHO} NO;						\
	fi
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.glu=${BUILDLINK_IS_BUILTIN.glu}
.endif

.if !defined(_NEED_GLU)
.  if !empty(BUILDLINK_IS_BUILTIN.glu:M[nN][oO])
_NEED_GLU=	YES
.  else
#
# Create an appropriate package name for the built-in Mesa/GLU distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
.      include "../../graphics/Mesa/version.mk"
_GLU_PKG=	glu-${_MESA_VERSION}
_GLU_DEPENDS=	${BUILDLINK_DEPENDS.glu}
_NEED_GLU!=	\
	if ${PKG_ADMIN} pmatch '${_GLU_DEPENDS}' ${_GLU_PKG}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
.endif	# _NEED_GLU

.if !empty(BUILDLINK_CHECK_BUILTIN.glu:M[yY][eE][sS])
_NEED_GLU=	NO
.endif

.if ${_NEED_GLU} == "YES"
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.glu=	glu>=5.0
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	glu
.  endif
.  if !defined(BUILDLINK_PACKAGES) || empty(BUILDLINK_PACKAGES:Mglu)
BUILDLINK_PACKAGES+=	glu
.  endif
.else
BUILDLINK_PREFIX.glu=	${X11BASE}
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
