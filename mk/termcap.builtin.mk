# $NetBSD: termcap.builtin.mk,v 1.2 2008/03/02 07:05:28 jlam Exp $

BUILTIN_PKG:=	termcap

BUILTIN_FIND_LIBS:=	curses termcap termlib tinfo

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.termcap)
IS_BUILTIN.termcap=	no
.  if !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS]) || \
      !empty(BUILTIN_LIB_FOUND.termcap:M[yY][eE][sS]) || \
      !empty(BUILTIN_LIB_FOUND.termlib:M[yY][eE][sS]) || \
      !empty(BUILTIN_LIB_FOUND.tinfo:M[yY][eE][sS])
IS_BUILTIN.termcap=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.termcap

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.termcap)
.  if ${PREFER.termcap} == "pkgsrc"
USE_BUILTIN.termcap=	no
.  else
USE_BUILTIN.termcap=	${IS_BUILTIN.termcap}
.  endif  # PREFER.termcap
.endif
MAKEVARS+=	USE_BUILTIN.termcap

# Define BUILTIN_LIBNAME.termcap to be the base name of the built-in
# termcap library.
#
# XXX This needs to be more sophisticated.  We will want to do what
# XXX most packages do: test for tgetent() in the following libraries
# XXX in order: c, curses, termcap, termlib.  Since we can't test for
# XXX symbols in libraries, we'll need to be clever with looking at
# XXX headers.
#
.if !empty(BUILTIN_LIB_FOUND.termcap:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	termcap
.elif !empty(BUILTIN_LIB_FOUND.tinfo:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	tinfo
.elif !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	curses
.elif !empty(BUILTIN_LIB_FOUND.termlib:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	termlib
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.termcap?=	no
.if !empty(CHECK_BUILTIN.termcap:M[nN][oO])

.  if !empty(USE_BUILTIN.termcap:M[yY][eE][sS])
BUILDLINK_LIBNAME.termcap=	${BUILTIN_LIBNAME.termcap}
.  endif

.endif	# CHECK_BUILTIN.termcap
