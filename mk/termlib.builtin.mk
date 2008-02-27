# $NetBSD: termlib.builtin.mk,v 1.1 2008/02/27 04:47:02 jlam Exp $

BUILTIN_PKG:=	termlib

BUILTIN_FIND_LIBS:=	termcap curses

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.termlib)
IS_BUILTIN.termlib=	no
.  if !empty(BUILTIN_LIB_FOUND.termcap:M[yY][eE][sS]) || \
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

# Define BUILTIN_LIBNAME.termlib to be the built-in terminal library
# only if we're using the built-in termlib.
#
.if !empty(USE_BUILTIN.termlib:M[yY][eE][sS])
.  if !empty(BUILTIN_LIB_FOUND.termcap:M[yY][eE][sS])
BUILTIN_LIBNAME.termlib=	termcap
.  elif !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
BUILTIN_LIBNAME.termlib=	curses
.  endif
.endif
