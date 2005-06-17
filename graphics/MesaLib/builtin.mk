# $NetBSD: builtin.mk,v 1.10 2005/06/17 15:54:06 jlam Exp $

BUILTIN_PKG:=	MesaLib

BUILTIN_FIND_FILES_VAR:=	H_MESALIB
BUILTIN_FIND_FILES.H_MESALIB=	${X11BASE}/include/GL/glx.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.MesaLib)
IS_BUILTIN.MesaLib=	no
.  if exists(${H_MESALIB})
BUILTIN_IMAKE_CHECK:=	MesaLib:BuildGLXLibrary
.    include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.MesaLib=	${BUILTIN_IMAKE_CHECK.MesaLib}
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.MesaLib

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.MesaLib) && \
    !empty(IS_BUILTIN.MesaLib:M[yY][eE][sS]) && \
    exists(${H_MESALIB})
.  include "../../graphics/Mesa/version.mk"
BUILTIN_PKG.MesaLib=	MesaLib-${BUILTIN_VERSION.Mesa}
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
.      for _dep_ in ${BUILDLINK_DEPENDS.MesaLib}
.        if !empty(USE_BUILTIN.MesaLib:M[yY][eE][sS])
USE_BUILTIN.MesaLib!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.MesaLib:Q}; then \
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
BUILDLINK_DEPENDS.MesaLib+=	MesaLib>=6.2.1nb2
BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
.    include "../../mk/pthread.buildlink3.mk"
.    include "../../mk/pthread.builtin.mk"
BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
.  endif

.  if !empty(USE_BUILTIN.MesaLib:M[yY][eE][sS])
BUILDLINK_PREFIX.MesaLib=	${X11BASE}
BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
.    include "../../mk/x11.buildlink3.mk"
.    include "../../mk/x11.builtin.mk"
BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
.  endif

.endif	# CHECK_BUILTIN.MesaLib
