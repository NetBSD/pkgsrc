# $NetBSD: buildlink3.mk,v 1.23 2004/02/12 01:59:38 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MESALIB_BUILDLINK3_MK:=	${MESALIB_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(MESALIB_BUILDLINK3_MK:M+)
MESA_REQD+=	3.4.2

# Distill the MESA_REQD list into a single _MESA_REQD value that is the
# highest version of MESA required.
#
_MESA_STRICTEST_REQD?=	none
.  for _version_ in ${MESA_REQD}
.    for _pkg_ in gcc-${_version_}
.      if ${_MESA_STRICTEST_REQD} == "none"
_MESA_PKG_SATISFIES_DEP=	YES
.        for _vers_ in ${MESA_REQD}
.          if !empty(_MESA_PKG_SATISFIES_DEP:M[yY][eE][sS])
_MESA_PKG_SATISFIES_DEP!=	\
	if ${PKG_ADMIN} pmatch 'gcc>=${_vers_}' ${_pkg_}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
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

BUILDLINK_PACKAGES+=		MesaLib
BUILDLINK_DEPENDS.MesaLib+=	MesaLib>=${_MESA_REQD}
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib
.endif	# MESALIB_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.MesaLib?=	NO

_GL_GLX_H=	${X11BASE}/include/GL/glx.h
_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.MesaLib)
BUILDLINK_IS_BUILTIN.MesaLib=	NO
.  if exists(${_GL_GLX_H}) && exists(${_X11_TMPL})
_IS_BUILTIN.MesaLib!=							\
	if ${GREP} -q BuildGLXLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.MesaLib=	${_IS_BUILTIN.MesaLib}
.    if !empty(BUILDLINK_CHECK_BUILTIN.MesaLib:M[nN][oO]) && \
        !empty(_IS_BUILTIN.MesaLib:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in Mesa/GLX distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
.      include "../../graphics/Mesa/version.mk"
_MESALIB_PKG=		MesaLib-${_MESA_VERSION}
BUILDLINK_IS_BUILTIN.MesaLib?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.MesaLib}
.        if !empty(BUILDLINK_IS_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.MesaLib!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_MESALIB_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.MesaLib=${BUILDLINK_IS_BUILTIN.MesaLib}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.MesaLib=	YES
.else
BUILDLINK_USE_BUILTIN.MesaLib=	NO
.endif

.if !empty(PREFER_PKGSRC:M[yY][eE][sS]) || \
    !empty(PREFER_PKGSRC:MMesaLib)
BUILDLINK_USE_BUILTIN.MesaLib=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.MesaLib=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.MesaLib:M[nN][oO])
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.MesaLib+=	MesaLib>=6.0
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		MesaLib
.  endif
.endif

.if !empty(MESALIB_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_PREFIX.MesaLib=	${X11BASE}
USE_X11=			yes
_MESA_REQD=			${_MESA_VERSION}
.  else
.    if !defined(BUILDING_MESA)
BUILDLINK_CPPFLAGS.MesaLib=	-DGLX_GLXEXT_LEGACY
.    endif
.  endif
.endif	# MESALIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
