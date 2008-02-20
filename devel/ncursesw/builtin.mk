# $NetBSD: builtin.mk,v 1.2 2008/02/20 20:07:25 jlam Exp $

BUILTIN_PKG:=	ncursesw

# H_NB_CURSESW searches for NetBSD's <curses.h> that uses HAVE_WCHAR to
#	build with wide curses support.
#
# XXX Need to deal with Solaris <curses.h>
#
BUILTIN_FIND_LIBS:=			ncursesw
BUILTIN_FIND_FILES_VAR:=		H_NB_CURSESW H_NCURSESW_CURSES
BUILTIN_FIND_FILES.H_NB_CURSESW=		/usr/include/curses.h
BUILTIN_FIND_GREP.H_NB_CURSESW=		\#ifdef[ 	]*HAVE_WCHAR
BUILTIN_FIND_FILES.H_NCURSESW_CURSES=	/usr/include/ncursesw/curses.h
BUILTIN_FIND_GREP.H_NCURSESW_CURSES=	\#define[ 	]*NCURSES_VERSION

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.ncursesw)
IS_BUILTIN.ncursesw=	no
.  if empty(H_NCURSESW_CURSES:M__nonexistent__) && \
      empty(H_NCURSESW_CURSES:M${LOCALBASE}/*) && \
      !empty(BUILTIN_LIB_FOUND.ncursesw:M[yY][eE][sS])
IS_BUILTIN.ncursesw=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.ncursesw

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.ncursesw) && \
    !empty(IS_BUILTIN.ncursesw:M[yY][eE][sS]) && \
    empty(H_NCURSES:M__nonexistent__)
BUILTIN_VERSION.ncursesw!=						\
	${AWK} '/\#define[ 	]*NCURSES_VERSION[ 	]/ {		\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${H_NCURSES:Q}
BUILTIN_PKG.ncursesw=	ncursesw-${BUILTIN_VERSION.ncursesw}
.endif
MAKEVARS+=	BUILTIN_PKG.ncursesw

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.ncursesw)
.  if ${PREFER.ncursesw} == "pkgsrc"
USE_BUILTIN.ncursesw=	no
.  else
USE_BUILTIN.ncursesw=	${IS_BUILTIN.ncursesw}
.    if defined(BUILTIN_PKG.ncursesw) && \
        !empty(IS_BUILTIN.ncursesw:M[yY][eE][sS])
USE_BUILTIN.ncursesw=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.ncursesw}
.        if !empty(USE_BUILTIN.ncursesw:M[yY][eE][sS])
USE_BUILTIN.ncursesw!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.ncursesw:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
# XXX
# XXX By default, assume that the native curses on NetBSD systems is
# XXX good enough to replace ncursesw.  In reality, no version of NetBSD
# XXX has a curses library that can completely replace ncursesw; however,
# XXX some versions implement enough of ncursesw that some packages are
# XXX happy.
# XXX
.    if empty(H_NB_CURSESW:M__nonexistent__) && \
	empty(H_NB_CURSESW:M${LOCALBASE}/*)
USE_BUILTIN.ncursesw=	yes
.    endif
.  endif  # PREFER.ncursesw
.endif
MAKEVARS+=	USE_BUILTIN.ncursesw

# If USE_NCURSESW is defined, then force the use of an ncurses/ncursesw
# implementation.
#
.if defined(USE_NCURSESW)
USE_NCURSES=		yes
.  if !empty(IS_BUILTIN.ncursesw:M[nN][oO])
USE_BUILTIN.ncursesw=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.ncursesw?=	no
.if !empty(CHECK_BUILTIN.ncursesw:M[nN][oO])

.  if !empty(USE_BUILTIN.ncursesw:M[yY][eE][sS])
.    if !empty(BUILTIN_LIB_FOUND.ncursesw:M[nN][oO])
BUILDLINK_TRANSFORM+=		l:ncursesw:curses
.    endif
.    if empty(H_NB_CURSESW:M__nonexistent__) && \
	empty(H_NB_CURSESW:M${LOCALBASE}/*)
BUILDLINK_CPPFLAGS.ncursesw+=	-DHAVE_WCHAR=1
.    endif
.  endif
BUILDLINK_TARGETS+=		buildlink-ncursesw-curses-h

# Packages will expect the following includes to provide declarations
# for ncursesw if wide curses are supported:
#
#	<ncursesw/curses.h>
#	<ncurses.h>
#	<curses.h>
#
# We must explicitly force the symlinks to be created as we have to
# overwrite any that ncurses/buildlink3.mk might create ahead of us.
#
.  if !target(buildlink-ncursesw-curses-h)
.PHONY: buildlink-ncursesw-curses-h
buildlink-ncursesw-curses-h:
	${RUN}								\
	curses_h="ncursesw/ncurses.h curses.h";				\
	for f in $$curses_h; do						\
		src=${BUILDLINK_PREFIX.ncursesw:Q}"/include/$$f";	\
		dests="ncursesw/curses.h ncurses.h curses.h";		\
		for dest in $$dests; do					\
			dest=${BUILDLINK_DIR:Q}"/include/$$dest";	\
			if ${TEST} -f "$$src"; then			\
				${ECHO_BUILDLINK_MSG} "Linking $$dest -> $$f."; \
				${MKDIR} `${DIRNAME} "$$dest"`;		\
				${LN} -fs "$$src" "$$dest";		\
			fi;						\
		done;							\
	done
.  endif

.endif	# CHECK_BUILTIN.ncursesw
