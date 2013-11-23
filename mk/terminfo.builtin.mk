# $NetBSD: terminfo.builtin.mk,v 1.5 2013/11/23 09:10:14 obache Exp $

BUILTIN_PKG:=	terminfo

BUILTIN_FIND_LIBS:=		terminfo curses tinfo
BUILTIN_FIND_HEADERS_VAR:=	H_TERM
BUILTIN_FIND_HEADERS.H_TERM:=	term.h
BUILTIN_FIND_GREP.H_TERM:=	tigetstr

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.terminfo)
IS_BUILTIN.terminfo=	no
.  if empty(H_TERM:M__nonexistent__) && empty(H_TERM:M${LOCALBASE}/*)
.    if !empty(BUILTIN_LIB_FOUND.terminfo:M[yY[eE][sS]) || \
        !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS]) || \
        !empty(BUILTIN_LIB_FOUND.tinfo:M[yY][eE][sS])
IS_BUILTIN.terminfo=	yes
.    endif
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.terminfo

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.terminfo)
.  if ${PREFER.terminfo} == "pkgsrc"
USE_BUILTIN.terminfo=	no
.  else
USE_BUILTIN.terminfo=	${IS_BUILTIN.terminfo}
.  endif  # PREFER.terminfo
.endif
MAKEVARS+=	USE_BUILTIN.terminfo

# Define BUILTIN_LIBNAME.terminfo to be the base name of the built-in
# terminfo library.
#
# The way this is determined is:
#
# (1) If <term.h> exists and libterminfo exists, then it's "terminfo".
# (1) If <term.h> exists and libtinfo exists, then it's "tinfo".
# (2) If <term.h> exists and libcurses exists, then it's "curses".
# (3) If <term.h> exists and lib{curses,terminfo,tinfo} don't, then it's "c".
#
.if empty(H_TERM:M__nonexistent__) && empty(H_TERM:M${LOCALBASE}/*)
.  if !empty(BUILTIN_LIB_FOUND.terminfo:M[yY][eE][sS])
BUILTIN_LIBNAME.terminfo=	terminfo
.  elif !empty(BUILTIN_LIB_FOUND.tinfo:M[yY][eE][sS])
BUILTIN_LIBNAME.terminfo=	tinfo
.  elif !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
BUILTIN_LIBNAME.terminfo=	curses
.  else
BUILTIN_LIBNAME.terminfo=	c
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.terminfo?=	no
.if !empty(CHECK_BUILTIN.terminfo:M[nN][oO])

.  if !empty(USE_BUILTIN.terminfo:M[yY][eE][sS])
BUILDLINK_LIBNAME.terminfo=	${BUILTIN_LIBNAME.terminfo}
.  endif

# If the package wants both "terminfo" and "curses", then we must not
# remove the -l options for the curses libraries; otherwise, we should
# remove them as GNU configure scripts commonly check for one or both
# of those library options.
#
.  if empty(BUILDLINK_TREE:Mcurses) && empty(BUILDLINK_TREE:Mncurses)
.    if empty(BUILDLINK_LIBNAME.terminfo:Mcurses)
BUILDLINK_TRANSFORM+=		rm:-lcurses
.    endif
.    if empty(BUILDLINK_LIBNAME.terminfo:Mncurses)
BUILDLINK_TRANSFORM+=		rm:-lncurses
.    endif
.  endif

.endif	# CHECK_BUILTIN.terminfo
