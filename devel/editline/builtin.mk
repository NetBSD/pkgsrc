# $NetBSD: builtin.mk,v 1.4 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=	editline

BUILTIN_FIND_LIBS:=		edit
BUILTIN_FIND_HEADERS_VAR:=	H_EDITLINE
BUILTIN_FIND_HEADERS.H_EDITLINE=editline/readline.h \
				readline/readline.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.editline)
IS_BUILTIN.editline=	no
.  if empty(H_EDITLINE:M__nonexistent__) && \
      !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS])
IS_BUILTIN.editline=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.editline

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.editline)
.  if ${PREFER.editline} == "pkgsrc"
USE_BUILTIN.editline=	no
.  else
USE_BUILTIN.editline=	${IS_BUILTIN.editline}
.    if defined(BUILTIN_PKG.editline) && \
        !empty(IS_BUILTIN.editline:M[yY][eE][sS])
USE_BUILTIN.editline=	yes
.    endif
MAKEVARS+=	USE_BUILTIN.editline
.  endif
.endif

CHECK_BUILTIN.editline?=	no
.if !empty(CHECK_BUILTIN.editline:M[nN][oO])

.  if !empty(USE_BUILTIN.editline:M[yY][eE][sS])
.    if !empty(H_EDITLINE:M/usr/include/editline/readline.h)
BUILDLINK_TARGETS+=	buildlink-readline-readline-h
BUILDLINK_TARGETS+=	buildlink-readline-history-h
.    endif

BUILDLINK_TRANSFORM+=	l:history:edit:${BUILTIN_LIBNAME.termcap}
BUILDLINK_TRANSFORM+=	l:readline:edit:${BUILTIN_LIBNAME.termcap}

.    if !target(buildlink-readline-readline-h)
.PHONY: buildlink-readline-readline-h
buildlink-readline-readline-h:
	${RUN}								\
	src=${H_EDITLINE:Q};						\
	dest=${BUILDLINK_DIR}"/include/readline/readline.h";		\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		fname=`${BASENAME} $$src`;				\
		${ECHO_BUILDLINK_MSG} "Linking $$fname -> readline.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.    endif

.    if !target(buildlink-readline-history-h)
.PHONY: buildlink-readline-history-h
buildlink-readline-history-h:
	${RUN}								\
	src=${H_EDITLINE:Q};						\
	dest=${BUILDLINK_DIR}"/include/readline/history.h";		\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		fname=`${BASENAME} $$src`;				\
		${ECHO_BUILDLINK_MSG} "Linking $$fname -> history.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.    endif
.  endif
.endif	# CHECK_BUILTIN.editline
