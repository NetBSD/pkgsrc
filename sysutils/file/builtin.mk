# $NetBSD: builtin.mk,v 1.7 2013/11/23 12:10:13 obache Exp $

BUILTIN_PKG:=	file

BUILTIN_FIND_HEADERS_VAR:=	H_FILE
BUILTIN_FIND_HEADERS.H_FILE=	magic.h
BUILTIN_FIND_GREP.H_FILE=	magic_file
BUILTIN_FIND_FILES_VAR:=	BIN_FILE
BUILTIN_FIND_FILES.BIN_FILE=	${TOOLS_PLATFORM.file} /bin/file /usr/bin/file

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
.  if empty(BIN_FILE:M__nonexistent__) && empty(BIN_FILE:M{LOCALBASE}/*)
BUILTIN_CMD.file=	${BIN_FILE}
.  else
BUILTIN_CMD.file=	file
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.file

.if !defined(BUILTIN_PKG.file) && !empty(IS_BUILTIN.file:M[yY][eE][sS])
BUILTIN_VERSION.file!=	${BUILTIN_CMD.file} --version 2>&1 | ${GREP} 'file-' | ${SED} 's/file-//'
BUILTIN_PKG.file=	file-${BUILTIN_VERSION.file}
.endif
MAKEVARS+=	BUILTIN_PKG.file

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
