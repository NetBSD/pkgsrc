# $NetBSD: builtin.mk,v 1.13 2025/04/30 21:09:49 tnn Exp $

BUILTIN_PKG:=	editline

BUILTIN_FIND_LIBS:=			edit
BUILTIN_FIND_HEADERS_VAR:=		H_EDITLINE
BUILTIN_FIND_HEADERS.H_EDITLINE=	editline/readline.h \
					readline/readline.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.editline)
IS_BUILTIN.editline=	no
.  if ${H_EDITLINE:U} != __nonexistent__ && \
      ${BUILTIN_LIB_FOUND.edit:U:tl} == yes
IS_BUILTIN.editline=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.editline

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
        ${IS_BUILTIN.editline:tl} == yes
USE_BUILTIN.editline=	yes
.    endif
MAKEVARS+=		USE_BUILTIN.editline
.  endif
.endif

CHECK_BUILTIN.editline?=	no
.if ${CHECK_BUILTIN.editline:tl} == no

.  if !empty(_PKG_USE_READLINE:U:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=	l:history:edit:${BUILTIN_LIBNAME.termcap}
BUILDLINK_TRANSFORM+=	l:readline:edit:${BUILTIN_LIBNAME.termcap}
.  endif

.  if ${USE_BUILTIN.editline:tl} == yes
BUILDLINK_TARGETS+=	ensure-libedit-pc
# TODO: version number is fixed when creating pkg-config file, should
# get this from the editline installation somehow
.PHONY: ensure-libedit-pc
ensure-libedit-pc:
	${RUN}								\
	dst=${BUILDLINK_DIR}/lib/pkgconfig/libedit.pc;			\
	src=${BUILDLINK_PREFIX.editline}/lib${LIBABISUFFIX}/pkgconfig/libedit.pc; \
	if [ ! -f $${dst} ]; then					\
		${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig;		\
		if [ -f $${src} ]; then					\
			${ECHO_BUILDLINK_MSG} "Symlinking $${src}";	\
			${LN} -sf $${src} $${dst};			\
		else							\
			${ECHO_BUILDLINK_MSG} "Creating $${dst}";	\
			{						\
			${ECHO} "prefix=${BUILDLINK_PREFIX.editline}";	\
			${ECHO} "exec_prefix=\$${prefix}";		\
			${ECHO} "libdir=\$${exec_prefix}/lib";		\
			${ECHO} "includedir=\$${prefix}/include";	\
			${ECHO} "";					\
			${ECHO} "Name: libedit";			\
			${ECHO} "Description: command line editor library providing generic line editing, history, and tokenization functions.";	\
			${ECHO} "Version: 3.1";				\
			${ECHO} "Libs: ${COMPILER_RPATH_FLAG}\$${libdir} -L\$${libdir} -ledit";	\
			${ECHO} "Libs.private: -ltermcap";		\
			${ECHO} "Cflags: -I\$${includedir} -I\$${includedir}/readline";		\
			} > $${dst};					\
		fi;							\
	fi

.    if !empty(H_EDITLINE:M*/editline/readline.h)
BUILDLINK_TARGETS+=	buildlink-readline-readline-h
BUILDLINK_TARGETS+=	buildlink-readline-history-h
.    endif

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
