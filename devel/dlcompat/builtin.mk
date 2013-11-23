# $NetBSD: builtin.mk,v 1.10 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=	dlcompat

BUILTIN_FIND_LIBS:=		dl
BUILTIN_FIND_HEADERS_VAR:=	H_DLFCN
BUILTIN_FIND_HEADERS.H_DLFCN=	dlfcn.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.dlcompat)
IS_BUILTIN.dlcompat=	no
.  if empty(H_DLFCN:M__nonexistent__) && empty(H_DLFCN:M${LOCALBASE}/*) && \
      !empty(BUILTIN_LIB_FOUND.dl:M[yY][eE][sS])
IS_BUILTIN.dlcompat=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.dlcompat

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.dlcompat) && \
    !empty(IS_BUILTIN.dlcompat:M[yY][eE][sS])
# XXX
# XXX Consider any built-in dlcompat to be from version 20030629.
# XXX
BUILTIN_PKG.dlcompat=	dlcompat-20030629
.endif
MAKEVARS+=	BUILTIN_PKG.dlcompat

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.dlcompat)
.  if ${PREFER.dlcompat} == "pkgsrc"
USE_BUILTIN.dlcompat=	no
.  else
USE_BUILTIN.dlcompat=	${IS_BUILTIN.dlcompat}
.    if defined(BUILTIN_PKG.dlcompat) && \
        !empty(IS_BUILTIN.dlcompat:M[yY][eE][sS])
USE_BUILTIN.dlcompat=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.dlcompat}
.        if !empty(USE_BUILTIN.dlcompat:M[yY][eE][sS])
USE_BUILTIN.dlcompat!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.dlcompat:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.dlcompat
.endif
MAKEVARS+=	USE_BUILTIN.dlcompat
