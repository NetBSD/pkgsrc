# $NetBSD: builtin.mk,v 1.20 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=	readline

BUILTIN_FIND_LIBS:=		readline history
BUILTIN_FIND_HEADERS_VAR:=	H_READLINE _BLTN_H_READLINE
BUILTIN_FIND_HEADERS.H_READLINE=readline/readline.h	\
				readline.h
BUILTIN_FIND_GREP.H_READLINE=	\#define[ 	]*RL_VERSION_MAJOR

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.readline)
IS_BUILTIN.readline=	no
.  if empty(H_READLINE:M__nonexistent__) && \
      empty(H_READLINE:M${LOCALBASE}/*) && \
      !empty(BUILTIN_LIB_FOUND.readline:M[yY][eE][sS])
IS_BUILTIN.readline=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.readline

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.readline) && \
    !empty(IS_BUILTIN.readline:M[yY][eE][sS]) && \
    empty(H_READLINE:M__nonexistent__)
BUILTIN_VERSION.readline!=						\
	${AWK} '/\#define[ 	]*RL_VERSION_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*RL_VERSION_MINOR/ { m = "."$$3 }	\
		END { printf "%s%s\n", M, m }				\
	' ${H_READLINE:Q}
BUILTIN_PKG.readline=	readline-${BUILTIN_VERSION.readline}
.endif
MAKEVARS+=	BUILTIN_PKG.readline

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.readline)
.  if ${PREFER.readline} == "pkgsrc"
USE_BUILTIN.readline=	no
.  else
USE_BUILTIN.readline=	${IS_BUILTIN.readline}
.    if defined(BUILTIN_PKG.readline) && \
        !empty(IS_BUILTIN.readline:M[yY][eE][sS])
USE_BUILTIN.readline=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.readline}
.        if !empty(USE_BUILTIN.readline:M[yY][eE][sS])
USE_BUILTIN.readline!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.readline:Q}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
#
# Some platforms don't have a readline/editline implementation that can
# replace GNU readline.
#
_INCOMPAT_READLINE?=	Darwin-[567].*-* Interix-*-*
.    if defined(OS_VARIANT) && empty(OS_VARIANT:MOmniOS)
_INCOMPAT_READLINE+=	SunOS-*-*
.    endif
.    for _pattern_ in ${_INCOMPAT_READLINE} ${INCOMPAT_READLINE}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.readline=	no
.      endif
.    endfor
.  endif  # PREFER.readline
.endif
MAKEVARS+=	USE_BUILTIN.readline

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.readline?=	no
.if !empty(CHECK_BUILTIN.readline:M[nN][oO])

.  if !empty(USE_BUILTIN.readline:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=	l:history:readline:${BUILTIN_LIBNAME.termcap}
.  endif

.endif	# CHECK_BUILTIN.readline
