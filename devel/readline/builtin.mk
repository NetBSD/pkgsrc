# $NetBSD: builtin.mk,v 1.15 2006/12/29 15:11:20 joerg Exp $

BUILTIN_PKG:=	readline

BUILTIN_FIND_LIBS:=		edit readline
BUILTIN_FIND_FILES_VAR:=	H_READLINE _BLTN_H_READLINE
BUILTIN_FIND_FILES.H_READLINE=	/usr/include/readline/readline.h	\
				/usr/include/readline.h
BUILTIN_FIND_FILES._BLTN_H_READLINE=	\
				/usr/include/readline/readline.h	\
				/usr/include/readline.h
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
# XXX
# XXX By default, assume that the native editline library is good enough
# XXX to replace GNU readline if it provides the readline-compatibility
# XXX headers.
# XXX
.    if !empty(BUILTIN_LIB_FOUND.readline:M[nN][oO]) && \
        !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS]) && \
	empty(_BLTN_H_READLINE:M__nonexistent__)
USE_BUILTIN.readline=	yes
.    endif
#
# Some platforms don't have a readline/editline implementation that can
# replace GNU readline.
#
_INCOMPAT_READLINE?=	SunOS-*-* Darwin-[567].*-* Interix-*-*
.    for _pattern_ in ${_INCOMPAT_READLINE} ${INCOMPAT_READLINE}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.readline=	no
.      endif
.    endfor
.  endif  # PREFER.readline
.endif
MAKEVARS+=	USE_BUILTIN.readline

# If USE_GNU_READLINE is defined, then force the use of a GNU readline
# implementation.
#
.if defined(USE_GNU_READLINE)
.  if !empty(IS_BUILTIN.readline:M[nN][oO])
USE_BUILTIN.readline=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.readline?=	no
.if !empty(CHECK_BUILTIN.readline:M[nN][oO])

.  if !empty(USE_BUILTIN.readline:M[yY][eE][sS])
.    if !empty(BUILTIN_LIB_FOUND.readline:M[Yy][Ee][Ss]) && ${OPSYS} == "OpenBSD"
BUILDLINK_TRANSFORM+=	l:history:readline:termcap
.    elif !empty(BUILTIN_LIB_FOUND.readline:M[nN][oO]) && \
        !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=	l:history:edit:termcap
BUILDLINK_TRANSFORM+=	l:readline:edit:termcap
.    endif
.  endif

.endif	# CHECK_BUILTIN.readline
