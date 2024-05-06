# $NetBSD: builtin.mk,v 1.50 2024/05/06 07:58:24 jperkin Exp $

BUILTIN_PKG:=	ncurses

BUILTIN_FIND_LIBS:=			ncurses curses terminfo
BUILTIN_FIND_HEADERS_VAR:=		H_NCURSES H_CURSES H_CURSES1
BUILTIN_FIND_HEADERS.H_NCURSES=		ncurses.h curses.h
#BUILTIN_FIND_HEADERS.H_NCURSES+=	ncurses/curses.h
BUILTIN_FIND_GREP.H_NCURSES=		\#define[ 	]*NCURSES_VERSION
BUILTIN_FIND_HEADERS.H_CURSES=		ncurses.h curses.h
BUILTIN_FIND_GREP.H_CURSES=		mvwchgat
BUILTIN_FIND_HEADERS.H_CURSES1=		ncurses.h curses.h
BUILTIN_FIND_GREP.H_CURSES1=		wsyncup
BUILTIN_FIND_FILES_VAR=			NCURSES_PC
BUILTIN_FIND_FILES.NCURSES_PC=		/usr/lib/pkgconfig/ncurses.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.ncurses)
IS_BUILTIN.ncurses=	no
.  if empty(H_NCURSES:M__nonexistent__) && \
      empty(H_NCURSES:M${LOCALBASE}/*) && \
      (${BUILTIN_LIB_FOUND.ncurses:U:tl} == yes || \
       ${BUILTIN_LIB_FOUND.curses:U:tl} == yes)
IS_BUILTIN.ncurses=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.ncurses

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.ncurses) && \
    ${IS_BUILTIN.ncurses:tl} == yes && \
    empty(H_NCURSES:M__nonexistent__)
BUILTIN_VERSION.ncurses!=						\
	${AWK} '/\#define[ 	]*NCURSES_VERSION[ 	]/ {		\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${_CROSS_DESTDIR:U:Q}${H_NCURSES:Q}
BUILTIN_PKG.ncurses=	ncurses-${BUILTIN_VERSION.ncurses}
.endif
MAKEVARS+=		BUILTIN_PKG.ncurses

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.ncurses)
.  if ${PREFER.ncurses} == "pkgsrc"
USE_BUILTIN.ncurses=	no
.  else
USE_BUILTIN.ncurses=	${IS_BUILTIN.ncurses}
.    if defined(BUILTIN_PKG.ncurses) && \
        ${IS_BUILTIN.ncurses:tl} == yes
USE_BUILTIN.ncurses=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.ncurses}
.        if ${USE_BUILTIN.ncurses:tl} == yes
USE_BUILTIN.ncurses!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.ncurses:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.ncurses
.endif
MAKEVARS+=		USE_BUILTIN.ncurses

# Define BUILTIN_LIBNAME.ncurses to be the base name of the built-in
# ncurses library.
#
.if ${BUILTIN_LIB_FOUND.ncurses:U:tl} == yes
BUILTIN_LIBNAME.ncurses=	ncurses
.elif ${BUILTIN_LIB_FOUND.curses:U:tl} == yes
BUILTIN_LIBNAME.ncurses=	curses
.endif
#
# On Interix, there is a libncurses.a and a libcurses.so but strangely,
# no libncurses.so.  We want to link against the shared library, so
# turn "-lncurses" into "-lcurses".
#
.if (${OPSYS} == "Interix") && \
    ${BUILTIN_LIB_FOUND.curses:U:tl} == yes
BUILTIN_LIBNAME.ncurses=	curses
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.ncurses?=	no
.if ${CHECK_BUILTIN.ncurses:tl} == no

.  if ${USE_BUILTIN.ncurses:tl} == yes
BUILDLINK_LIBNAME.ncurses=	${BUILTIN_LIBNAME.ncurses}
BUILDLINK_TRANSFORM+=		l:ncurses:${BUILTIN_LIBNAME.ncurses}
BUILDLINK_TARGETS+=		buildlink-curses-ncurses-h
BUILDLINK_TARGETS+=		buildlink-ncurses-extra-includes
# NetBSD 8 at least does not have ncurses.pc
BUILDLINK_TARGETS+=		ncurses-fake-pc
.  else
BUILDLINK_TRANSFORM+=		l:form:gnuform
BUILDLINK_TRANSFORM+=		l:panel:gnupanel
BUILDLINK_TRANSFORM+=		l:menu:gnumenu
.  endif

# A full ncurses implementation provides more headers than some curses
# implementations.  Touch empty replacements for those headers so that
# packages can continue to use the familiar ncurses header names.
#
.  if !target(buildlink-ncurses-extra-includes)
.PHONY: buildlink-ncurses-extra-includes
buildlink-ncurses-extra-includes:
	${RUN}								\
	extra_includes="include/term.h";				\
	for f in $$extra_includes; do					\
		src=${BUILDLINK_PREFIX.ncurses}"/$$f";			\
		dest=${BUILDLINK_DIR}"/$$f";				\
		if ${TEST} ! -f "$$src"; then				\
			${ECHO_BUILDLINK_MSG} "Touching extra ncurses header ($$f)"; \
			${MKDIR} `${DIRNAME} "$$dest"`;			\
			${TOUCH} ${TOUCH_FLAGS} "$$dest";		\
		fi;							\
	done
.  endif

.  if !target(buildlink-curses-ncurses-h)
.PHONY: buildlink-curses-ncurses-h
buildlink-curses-ncurses-h:
	${RUN}								\
	src=${H_NCURSES:Q};						\
	for file in ncurses.h ncurses/ncurses.h; do			\
		dest=${BUILDLINK_DIR}"/include/$$file";			\
		if ${TEST} ! -f "$$dest" -a -f "$$src"; then		\
			fname=`${BASENAME} $$src`;			\
			${ECHO_BUILDLINK_MSG} "Linking $$fname -> $$file."; \
			${MKDIR} `${DIRNAME} "$$dest"`;			\
			${LN} -s "$$src" "$$dest";			\
		fi;							\
	done
.  endif

.  if !target(ncurses-fake-pc)
.PHONY: ncurses-fake-pc
ncurses-fake-pc:
	${RUN}						\
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig;	\
	src=${NCURSES_PC}				\
	dst=${BUILDLINK_DIR}/lib/pkgconfig/ncurses.pc;	\
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		{	${ECHO} "Name: ncurses";			\
			${ECHO} "Description: ncurses library";		\
			${ECHO} "Version: ${BUILTIN_VERSION.ncurses}";	\
			${ECHO} "Libs: -L/usr/lib -lncurses";		\
			${ECHO} "Cflags: -I/usr/include";		\
		} >$${dst} ;\
	fi
.  endif

.endif	# CHECK_BUILTIN.ncurses
