# $NetBSD: builtin.mk,v 1.11.22.1 2008/09/26 19:59:46 cube Exp $

BUILTIN_PKG:=	glu

BUILTIN_FIND_FILES_VAR:=	H_GLU
BUILTIN_FIND_FILES.H_GLU=	${X11BASE}/include/GL/glu.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.glu)
IS_BUILTIN.glu=	no
.  if empty(H_GLU:M__nonexistent__)
BUILTIN_IMAKE_CHECK:=	glu:BuildGLULibrary
.    include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.glu=		${BUILTIN_IMAKE_CHECK.glu}
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.glu

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.glu) && \
    !empty(IS_BUILTIN.glu:M[yY][eE][sS]) && \
    empty(H_GLU:M__nonexistent__)
.  include "../../graphics/Mesa/version.mk"
BUILTIN_PKG.glu=	glu-${BUILTIN_VERSION.Mesa}
.endif
MAKEVARS+=	BUILTIN_PKG.glu

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.glu)
.  if ${PREFER.glu} == "pkgsrc"
USE_BUILTIN.glu=	no
.  else
USE_BUILTIN.glu=	${IS_BUILTIN.glu}
.    if defined(BUILTIN_PKG.glu) && \
        !empty(IS_BUILTIN.glu:M[yY][eE][sS])
USE_BUILTIN.glu=	yes
.      for dep in ${BUILDLINK_API_DEPENDS.glu}
.        if !empty(USE_BUILTIN.glu:M[yY][eE][sS])
USE_BUILTIN.glu!=							\
	if ${PKG_ADMIN} pmatch ${dep:Q} ${BUILTIN_PKG.glu:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.glu
.endif
MAKEVARS+=	USE_BUILTIN.glu

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.glu?=	no
.if !empty(CHECK_BUILTIN.glu:M[nN][oO])

.  if !empty(USE_BUILTIN.glu:M[nN][oO])
BUILDLINK_API_DEPENDS.glu+=	glu>=6.0
.  endif

.endif	# CHECK_BUILTIN.glu
