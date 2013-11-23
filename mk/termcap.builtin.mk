# $NetBSD: termcap.builtin.mk,v 1.10 2013/11/23 09:10:14 obache Exp $

BUILTIN_PKG:=	termcap

BUILTIN_FIND_LIBS:=		terminfo curses termcap termlib tinfo
BUILTIN_FIND_HEADERS_VAR:=	H_TERM H_TERMCAP H_TERMLIB
BUILTIN_FIND_HEADERS.H_TERM:=	term.h
BUILTIN_FIND_GREP.H_TERM:=	tgetent
BUILTIN_FIND_HEADERS.H_TERMCAP:=	termcap.h
BUILTIN_FIND_GREP.H_TERMCAP:=	tgetent
BUILTIN_FIND_HEADERS.H_TERMLIB:=	termlib.h
BUILTIN_FIND_GREP.H_TERMLIB:=	tgetent

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.termcap)
IS_BUILTIN.termcap=	no
.  if empty(H_TERM:M__nonexistent__) && empty(H_TERM:M${LOCALBASE}/*) || \
      empty(H_TERMCAP:M__nonexistent__) && empty(H_TERMCAP:M${LOCALBASE}/*) || \
      empty(H_TERMLIB:M__nonexistent__) && empty(H_TERMLIB:M${LOCALBASE}/*) || \
      !empty(BUILTIN_LIB_FOUND.termlib:M[yY][eE][sS])
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
# The way this is determined is:
#
# (1) If <term.h> exists and libtinfo exists, then it's "tinfo".
# (2) If <term.h> exists and libcurses exists, then it's "curses".
# (3) If <term.h> exists and lib{curses,tinfo} don't, then it's "c".
# (4) If <termcap.h> exists and libtermcap exists, then it's "termcap".
# (5) If <termcap.h> exists and libtermcap doesn't, then it's "c".
# (6) If <termlib.h> exists and libtermlib exists, then it's "termlib".
# (7) If <termlib.h> exists and libtermlib doesn't, then it's "c".
# (8) If libtermlib exists by itself, then it's "termlib".
#
.if empty(H_TERM:M__nonexistent__) && empty(H_TERM:M${LOCALBASE}/*)
.  if !empty(BUILTIN_LIB_FOUND.terminfo:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	terminfo
.  elif !empty(BUILTIN_LIB_FOUND.tinfo:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	tinfo
.  elif !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	curses
.  else
BUILTIN_LIBNAME.termcap=	c
.  endif
.elif empty(H_TERMCAP:M__nonexistent__) && empty(H_TERMCAP:M${LOCALBASE}/*)
.  if !empty(BUILTIN_LIB_FOUND.termcap:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	termcap
.  else
BUILTIN_LIBNAME.termcap=	c
.  endif
.elif empty(H_TERMLIB:M__nonexistent__) && empty(H_TERMLIB:M${LOCALBASE}/*)
.  if !empty(BUILTIN_LIB_FOUND.termlib:M[yY][eE][sS])
BUILTIN_LIBNAME.termcap=	termlib
.  else
BUILTIN_LIBNAME.termcap=	c
.  endif
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

# If the package wants both "termcap" and "curses", then we must not
# remove the -l options for the curses libraries; otherwise, we should
# remove them as GNU configure scripts commonly check for one or both
# of those library options.
#
.  if empty(BUILDLINK_TREE:Mcurses) && empty(BUILDLINK_TREE:Mncurses)
BUILDLINK_TRANSFORM+=		rm:-lcurses
BUILDLINK_TRANSFORM+=		rm:-lncurses
.  endif

.endif	# CHECK_BUILTIN.termcap
