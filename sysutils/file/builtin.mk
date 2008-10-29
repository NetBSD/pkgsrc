# $NetBSD: builtin.mk,v 1.5 2008/10/29 20:50:16 christos Exp $

BUILTIN_PKG:=	file

BUILTIN_FIND_FILES_VAR:=	H_FILE
BUILTIN_FIND_FILES.H_FILE=	/usr/include/magic.h
BUILTIN_FIND_GREP.H_FILE=	magic_file

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.file)
IS_BUILTIN.file=	no
.  if empty(H_FILE:M__nonexistent__) && empty(H_FILE:M${LOCALBASE}/*)
IS_BUILTIN.file=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.file

.if !defined(BUILTIN_PKG.file) && !empty(IS_BUILTIN.file:M[yY][eE][sS])
BUILTIN_VERSION.file!=	file --version 2>&1 | ${GREP} 'file-' | ${SED} 's/file-//'
BUILTIN_PKG.file=	file-${BUILTIN_VERSION.file}
.endif

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.file)
.  if ${PREFER.file} == "pkgsrc"
USE_BUILTIN.file=	no
.  else
USE_BUILTIN.file=	${IS_BUILTIN.file}
.    if defined(BUILTIN_PKG.file) && \
        !empty(IS_BUILTIN.file:M[yY][eE][sS])
USE_BUILTIN.file=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.file}
.        if !empty(USE_BUILTIN.file:M[yY][eE][sS])
USE_BUILTIN.file!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.file:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.file
.endif
MAKEVARS+=	USE_BUILTIN.file
