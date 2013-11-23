# $NetBSD: builtin.mk,v 1.2 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=	argp

BUILTIN_FIND_HEADERS_VAR:=	H_ARGP
BUILTIN_FIND_HEADERS.H_ARGP=	argp.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.argp)
IS_BUILTIN.argp=	no
.  if empty(H_ARGP:M__nonexistent__) && empty(H_ARGP:M${LOCALBASE}/*)
IS_BUILTIN.argp=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.argp

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.argp) && \
    !empty(IS_BUILTIN.argp:M[yY][eE][sS]) && \
    empty(H_ARGP:M__nonexistent__)

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.argp)
.  if ${PREFER.argp} == "pkgsrc"
USE_BUILTIN.argp=	no
.  else
USE_BUILTIN.argp=	${IS_BUILTIN.argp}
.    if defined(BUILTIN_PKG.argp) && \
        !empty(IS_BUILTIN.argp:M[yY][eE][sS])
USE_BUILTIN.argp=	yes
.    endif
.  endif  # PREFER.argp
.endif
MAKEVARS+=	USE_BUILTIN.argp
.endif
