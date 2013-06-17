# $NetBSD: builtin.mk,v 1.14 2013/06/17 05:27:50 dholland Exp $

BUILTIN_PKG:=	glu

BUILTIN_FIND_FILES_VAR:=	H_GLU PC_GLU
BUILTIN_FIND_FILES.H_GLU=	${X11BASE}/include/GL/glu.h
BUILTIN_FIND_FILES.PC_GLU=	${X11BASE}/lib/pkgconfig/glu.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.glu)
.  if empty(PC_GLU:M__nonexistent__)
IS_BUILTIN.glu=	yes
.  elif empty(H_GLU:M__nonexistent__)
IS_BUILTIN.glu=	yes
.  else
IS_BUILTIN.glu=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.glu

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.glu) && \
    !empty(IS_BUILTIN.glu:M[yY][eE][sS])
.  if empty(PC_GLU:M__nonexistent__)
BUILTIN_VERSION.Mesa!= ${SED} -n -e 's/Version: //p' ${PC_GLU}
.  elif empty(H_GLU:M__nonexistent__)
.    include "../../graphics/Mesa/version.mk"
.  else # ?
BUILTIN_VERSION.Mesa:= 0.something-weird-happened
.  endif
BUILTIN_PKG.glu=	glu-${BUILTIN_VERSION.Mesa}
MAKEVARS+=	BUILTIN_VERSION.Mesa
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
