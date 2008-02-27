# $NetBSD: curses.builtin.mk,v 1.2 2008/02/27 02:26:07 jlam Exp $

BUILTIN_PKG:=	curses

BUILTIN_FIND_LIBS:=		curses
BUILTIN_FIND_FILES_VAR:=	H_CURSES
BUILTIN_FIND_FILES.H_CURSES=	/usr/include/curses.h

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.curses)
IS_BUILTIN.curses=	no
.  if empty(H_CURSES:M${LOCALBASE}/*) && exists(${H_CURSES})
IS_BUILTIN.curses=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.curses

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.curses)
.  if ${PREFER.curses} == "pkgsrc"
USE_BUILTIN.curses=	no
.  else
USE_BUILTIN.curses=	${IS_BUILTIN.curses}
.    if defined(BUILTIN_PKG.curses) && !empty(IS_BUILTIN.curses:M[yY][eE][sS])
USE_BUILTIN.curses=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.curses}
.        if !empty(USE_BUILTIN.curses:M[yY][eE][sS])
USE_BUILTIN.curses!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.curses:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.curses
.endif
MAKEVARS+=	USE_BUILTIN.curses

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.curses?=	no
.if !empty(CHECK_BUILTIN.curses:M[nN][oO])

.  if !empty(USE_BUILTIN.curses:M[yY][eE][sS])
.    if exists(${H_CURSES})
BUILDLINK_INCDIRS.curses?=	${H_CURSES:H:S/^${BUILDLINK_PREFIX.curses}\///}
.    endif
.    if !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
BUILDLINK_LDADD.curses?=	-lcurses
.    endif
.  endif

.endif	# CHECK_BUILTIN.curses
