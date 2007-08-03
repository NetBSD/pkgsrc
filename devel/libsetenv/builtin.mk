# $NetBSD: builtin.mk,v 1.1.1.1 2007/08/03 21:30:59 tnn Exp $
#

BUILTIN_PKG:=	libsetenv

BUILTIN_FIND_FILES_VAR:=        H_STDLIB
BUILTIN_FIND_FILES.H_STDLIB=    /usr/include/stdlib.h
BUILTIN_FIND_GREP.H_STDLIB=     setenv

.include "../../mk/buildlink3/bsd.builtin.mk"

#
###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libsetenv)
IS_BUILTIN.libsetenv=	no
.  if empty(H_STDLIB:M__nonexistent__)
IS_BUILTIN.libsetenv=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libsetenv
#
###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libsetenv) && \
    !empty(IS_BUILTIN.libsetenv:M[yY][eE][sS])
BUILTIN_PKG.libsetenv=	libsetenv-0.1
.endif
MAKEVARS+=	BUILTIN_PKG.libsetenv
#
###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libsetenv)
.  if ${PREFER.libsetenv} == "pkgsrc"
USE_BUILTIN.libsetenv=	no
.  else
USE_BUILTIN.libsetenv=	${IS_BUILTIN.libsetenv}
.    if defined(BUILTIN_PKG.libsetenv) && \
        !empty(IS_BUILTIN.libsetenv:M[yY][eE][sS])
USE_BUILTIN.libsetenv=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libsetenv}
.        if !empty(USE_BUILTIN.libsetenv:M[yY][eE][sS])
USE_BUILTIN.libsetenv!=							\
if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libsetenv:Q}; then	\
	${ECHO} "yes";						\
else								\
	${ECHO} "no";						\
fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.libsetenv
#
###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.libsetenv?=	no
.if !empty(CHECK_BUILTIN.libsetenv:M[nN][oO])

.  if !empty(USE_BUILTIN.libsetenv:M[nN][oO])
_BLTN_LIBSETENV=	-lsetenv
.  else
_BLTN_LIBSETENV=	# empty
.  endif
BUILDLINK_LDADD.libsetenv?=	${_BLTN_LIBSETENV}

CONFIGURE_ENV+=		LIBSETENV=${BUILDLINK_LDADD.libsetenv:Q}
MAKE_ENV+=		LIBSETENV=${BUILDLINK_LDADD.libsetenv:Q}

.endif  # CHECK_BUILTIN.libsetenv
