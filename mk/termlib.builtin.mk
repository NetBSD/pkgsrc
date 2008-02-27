# $NetBSD: termlib.builtin.mk,v 1.3 2008/02/27 17:36:34 jlam Exp $

BUILTIN_PKG:=	termlib

BUILTIN_FIND_LIBS:=	termcap tinfo curses

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.termlib)
IS_BUILTIN.termlib=	no
.  if !empty(BUILTIN_LIB_FOUND.termcap:M[yY][eE][sS]) || \
      !empty(BUILTIN_LIB_FOUND.tinfo:M[yY][eE][sS]) || \
      !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
IS_BUILTIN.termlib=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.termlib

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.termlib)
.  if ${PREFER.termlib} == "pkgsrc"
USE_BUILTIN.termlib=	no
.  else
USE_BUILTIN.termlib=	${IS_BUILTIN.termlib}
.  endif  # PREFER.termlib
.endif
MAKEVARS+=	USE_BUILTIN.termlib

# Define BUILTIN_LIBNAME.termlib to be the base name of the built-in
# terminal library.
#
.if !empty(BUILTIN_LIB_FOUND.termcap:M[yY][eE][sS])
BUILTIN_LIBNAME.termlib=	termcap
.elif !empty(BUILTIN_LIB_FOUND.tinfo:M[yY][eE][sS])
BUILTIN_LIBNAME.termlib=	tinfo
.elif !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
BUILTIN_LIBNAME.termlib=	curses
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.termlib?=	no
.if !empty(CHECK_BUILTIN.termlib:M[nN][oO])

.  if !empty(USE_BUILTIN.termlib:M[yY][eE][sS])
BUILDLINK_LIBNAME.termlib=	${BUILTIN_LIBNAME.termlib}
.  endif

.endif	# CHECK_BUILTIN.termlib
