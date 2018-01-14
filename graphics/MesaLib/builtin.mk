# $NetBSD: builtin.mk,v 1.21 2018/01/14 14:58:38 rillig Exp $

BUILTIN_PKG:=	MesaLib

BUILTIN_FIND_FILES_VAR:=	H_MESALIB PC_GL
BUILTIN_FIND_FILES.H_MESALIB=	${X11BASE}/include/GL/glx.h
BUILTIN_FIND_FILES.PC_GL=	${X11BASE}/lib/pkgconfig/gl.pc
BUILTIN_FIND_FILES.PC_GL+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/gl.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.MesaLib)
.  if empty(PC_GL:M__nonexistent__)
IS_BUILTIN.MesaLib=	yes
.  elif empty(H_MESALIB:M__nonexistent__)
IS_BUILTIN.MesaLib=	yes
.  else
IS_BUILTIN.MesaLib=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.MesaLib

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.MesaLib) && \
    !empty(IS_BUILTIN.MesaLib:M[yY][eE][sS])
.  if empty(PC_GL:M__nonexistent__)
BUILTIN_VERSION.Mesa!= ${SED} -n -e 's/Version: //p' ${PC_GL}
.  elif empty(H_MESALIB:M__nonexistent__)
.    include "../../graphics/Mesa/version.mk"
.  else # ?
BUILTIN_VERSION.Mesa:= 0.something-weird-happened
.  endif
BUILTIN_PKG.MesaLib=	MesaLib-${BUILTIN_VERSION.Mesa}
MAKEVARS+=	BUILTIN_VERSION.Mesa
.endif
MAKEVARS+=	BUILTIN_PKG.MesaLib

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.MesaLib)
.  if ${PREFER.MesaLib} == "pkgsrc"
USE_BUILTIN.MesaLib=	no
.  else
USE_BUILTIN.MesaLib=	${IS_BUILTIN.MesaLib}
.    if defined(BUILTIN_PKG.MesaLib) && \
        !empty(IS_BUILTIN.MesaLib:M[yY][eE][sS])
USE_BUILTIN.MesaLib=	yes
.      for dep in ${BUILDLINK_API_DEPENDS.MesaLib}
.        if !empty(USE_BUILTIN.MesaLib:M[yY][eE][sS])
USE_BUILTIN.MesaLib!=							\
	if ${PKG_ADMIN} pmatch ${dep:Q} ${BUILTIN_PKG.MesaLib}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.MesaLib
.endif
MAKEVARS+=	USE_BUILTIN.MesaLib

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.MesaLib?=	no
.if !empty(CHECK_BUILTIN.MesaLib:M[nN][oO])

.  if !empty(USE_BUILTIN.MesaLib:M[nN][oO])
.    include "../../mk/pthread.buildlink3.mk"
.    include "../../mk/pthread.builtin.mk"
BUILTIN_PKG:=	MesaLib
.  endif

.  include "../../mk/x11.builtin.mk"

.endif	# CHECK_BUILTIN.MesaLib
