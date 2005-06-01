# $NetBSD: builtin.mk,v 1.8 2005/06/01 18:02:44 jlam Exp $

BUILTIN_PKG:=	ncurses

BUILTIN_FIND_LIBS:=		ncurses
BUILTIN_FIND_FILES_VAR:=	H_NCURSES
BUILTIN_FIND_FILES.H_NCURSES=	/usr/include/curses.h
BUILTIN_FIND_GREP.H_NCURSES=	\#define[ 	]*NCURSES_VERSION

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.ncurses)
IS_BUILTIN.ncurses=	no
.  if empty(H_NCURSES:M${LOCALBASE}/*) && exists(${H_NCURSES}) && \
      !empty(BUILTIN_LIB_FOUND.ncurses:M[yY][eE][sS])
IS_BUILTIN.ncurses=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.ncurses

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.ncurses) && \
    !empty(IS_BUILTIN.ncurses:M[yY][eE][sS]) && \
    exists(${H_NCURSES})
BUILTIN_VERSION.ncurses!=						\
	${AWK} '/\#define[ 	]*NCURSES_VERSION[ 	]/ {		\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${H_NCURSES:Q}
BUILTIN_PKG.ncurses=	ncurses-${BUILTIN_VERSION.ncurses}
.endif
MAKEVARS+=	BUILTIN_PKG.ncurses

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
        !empty(IS_BUILTIN.ncurses:M[yY][eE][sS])
USE_BUILTIN.ncurses=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.ncurses}
.        if !empty(USE_BUILTIN.ncurses:M[yY][eE][sS])
USE_BUILTIN.ncurses!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.ncurses:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
# XXX
# XXX By default, assume that the native curses on NetBSD systems is
# XXX good enough to replace ncurses.  In reality, no version of NetBSD
# XXX has a curses library that can completely replace ncurses; however,
# XXX some versions implement enough of ncurses that some packages are
# XXX happy.
# XXX
.    if ${OPSYS} == "NetBSD"
USE_BUILTIN.ncurses=	yes
.    endif
#
# Some platforms don't have a curses implementation that can replace
# ncurses.
#
_INCOMPAT_CURSES?=	NetBSD-0.*-* NetBSD-1.[0123]*-*			\
			NetBSD-1.4.*-* NetBSD-1.4[A-X]-*
.    for _pattern_ in ${_INCOMPAT_CURSES} ${INCOMPAT_CURSES}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.ncurses=	no
.      endif
.    endfor
.  endif  # PREFER.ncurses
.endif
MAKEVARS+=	USE_BUILTIN.ncurses

# If USE_NCURSES is defined, then force the use of an ncurses
# implementation.
#
.if defined(USE_NCURSES)
.  if !empty(IS_BUILTIN.ncurses:M[nN][oO])
USE_BUILTIN.ncurses=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.ncurses?=	no
.if !empty(CHECK_BUILTIN.ncurses:M[nN][oO])

.  if !empty(USE_BUILTIN.ncurses:M[yY][eE][sS])
.    if !empty(BUILTIN_LIB_FOUND.ncurses:M[nN][oO]) || (${OPSYS} == "Interix")
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses\.h|/ncurses.h|g"
BUILDLINK_TRANSFORM+=		l:ncurses:curses
.    endif
BUILDLINK_FILES.ncurses+=	include/curses.h
BUILDLINK_TARGETS+=		buildlink-ncurses-extra-includes
.  endif
BUILDLINK_TARGETS+=		buildlink-ncurses-curses-h

# A full ncurses implementation provides more headers than some curses
# implementations.  Touch empty replacements for those headers so that
# packages can continue to use the familiar ncurses header names.
#
.  if !target(buildlink-ncurses-extra-includes)
.PHONY: buildlink-ncurses-extra-includes
buildlink-ncurses-extra-includes:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extra_includes="include/term.h";				\
	for f in $$extra_includes; do					\
		src=${BUILDLINK_PREFIX.ncurses:Q}"/$$f";		\
		dest=${BUILDLINK_DIR:Q}"/$$f";				\
		if ${TEST} ! -f "$$src"; then				\
			${ECHO_BUILDLINK_MSG} "Touching extra ncurses header ($$f)"; \
			${MKDIR} `${DIRNAME} "$$dest"`;			\
			${TOUCH} ${TOUCH_FLAGS} "$$dest";		\
		fi;							\
	done
.  endif

# Some packages expect <curses.h> to provide declarations for ncurses.
.  if !target(buildlink-ncurses-curses-h)
.PHONY: buildlink-ncurses-curses-h
buildlink-ncurses-curses-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	src=${BUILDLINK_PREFIX.ncurses:Q}"/include/ncurses.h";		\
	dest=${BUILDLINK_DIR:Q}"/include/curses.h";			\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		${ECHO_BUILDLINK_MSG} "Linking curses.h -> ncurses.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.  endif

.endif	# CHECK_BUILTIN.ncurses
