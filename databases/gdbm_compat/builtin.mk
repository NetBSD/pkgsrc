# $NetBSD: builtin.mk,v 1.4 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=			gdbm_compat
BUILTIN_FIND_HEADERS_VAR=	NDBM_H
BUILTIN_FIND_HEADERS.NDBM_H=	ndbm.h
BUILTIN_FIND_GREP.NDBM_H=	This file is part of GDBM

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.gdbm_compat)
IS_BUILTIN.gdbm_compat=	no
.  if empty(NDBM_H:M__nonexistent__)
IS_BUILTIN.gdbm_compat=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.gdbm_compat

##
## Include databases/gdbm/builtin.mk so that BUILTIN_PKG.gdbm and
## USE_BUILTIN.gdbm are set.
.if !defined(BUILTIN_PKG.gdbm) || !defined(USE_BUILTIN.gdbm)
.  include "../../databases/gdbm/builtin.mk"
.endif

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.gdbm_compat) && \
    !empty(IS_BUILTIN.gdbm_compat:M[yY][eE][sS])
BUILTIN_PKG.gdbm_compat:= ${BUILTIN_PKG.gdbm:S/gdbm-/gdbm_compat-/}
.endif
MAKEVARS+=	BUILTIN_PKG.gdbm_compat

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
### Don't use builtin gdbm_compat unless also using builtin gdbm.
.if !defined(USE_BUILTIN.gdbm_compat)
.  if ${USE_BUILTIN.gdbm} == "no" || ${PREFER.gdbm_compat} == "pkgsrc"
USE_BUILTIN.gdbm_compat=	no
.  else
USE_BUILTIN.gdbm_compat=	${IS_BUILTIN.gdbm_compat}
.    if defined(BUILTIN_PKG.gdbm_compat) && \
	!empty(IS_BUILTIN.gdbm_compat:M[yY][eE][sS])
USE_BUILTIN.gdbm_compat=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.gdbm_compat}
.        if !empty(USE_BUILTIN.gdbm_compat:M[yY][eE][sS])
USE_BUILTIN.gdbm_compat!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.gdbm_compat:Q}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.gdbm_compat
