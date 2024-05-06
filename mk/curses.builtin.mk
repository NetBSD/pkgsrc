# $NetBSD: curses.builtin.mk,v 1.23 2024/05/06 09:35:14 jperkin Exp $

BUILTIN_PKG:=	curses

BUILTIN_FIND_LIBS:=				curses
BUILTIN_FIND_HEADERS_VAR:=			H_CURSES
BUILTIN_FIND_HEADERS.H_CURSES=			curses.h

# Functions and defines to search for.
# These are valid USE_CURSES options and will determine whether the
# package can use the built-in curses or not.
#
BUILTIN_TEST_CURSES_FUNCS=	chgat getsyx halfdelay putwin
BUILTIN_TEST_CURSES_FUNCS+=	resize_term resizeterm ripoffline set_escdelay syncok
BUILTIN_TEST_CURSES_FUNCS+=	wgetnstr wsyncup mvwchgat vw_printw
BUILTIN_TEST_CURSES_FUNCS+=	getmouse
BUILTIN_TEST_CURSES_DEFINES=	WA_NORMAL

.for func in ${BUILTIN_TEST_CURSES_FUNCS}
BUILTIN_FIND_FILES_VAR+=			H_CURSES_${func:tu}
BUILTIN_FIND_FILES.H_CURSES_${func:tu}=		${H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_${func:tu}=		${func}
.endfor

.for defn in ${BUILTIN_TEST_CURSES_DEFINES}
BUILTIN_FIND_FILES_VAR+=			H_CURSES_${defn}
BUILTIN_FIND_FILES.H_CURSES_${defn}=		${H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_${defn}=		${defn}
.endfor

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.curses)
IS_BUILTIN.curses=	no
.  if empty(H_CURSES:M${LOCALBASE}/*) && \
      exists(${TOOLS_CROSS_DESTDIR}${H_CURSES})
IS_BUILTIN.curses=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.curses

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.curses)
.  if ${PREFER.curses} == "pkgsrc"
USE_BUILTIN.curses=	no
.  else
USE_BUILTIN.curses=	${IS_BUILTIN.curses}
.    if defined(BUILTIN_PKG.curses) && ${IS_BUILTIN.curses:tl} == yes
USE_BUILTIN.curses=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.curses}
.        if ${USE_BUILTIN.curses:tl} == yes
USE_BUILTIN.curses!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.curses:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.curses
.endif

# If it is set to chgat, a curses implementation with chgat(3) support
# is considered good enough.
.if ${USE_CURSES:U:tl} != yes
.  for func in ${BUILTIN_TEST_CURSES_FUNCS}
.    if !empty(USE_CURSES:M${func}) && \
	!empty(H_CURSES_${func:tu}:M__nonexistent__)
USE_BUILTIN.curses=	no
.    endif
.  endfor
.  for defn in ${BUILTIN_TEST_CURSES_DEFINES}
.    if !empty(USE_CURSES:M${defn}) && \
	!empty(H_CURSES_${defn}:M__nonexistent__)
USE_BUILTIN.curses=	no
.    endif
.  endfor
# AFAIK there is no way of working out if a system curses library has wide
# character support. So be safe and say no unless we know for sure.
.  if ${USE_CURSES:U:Mwide}
.    if ${OPSYS} == "NetBSD"
.      if ${MACHINE_PLATFORM:MNetBSD-[0-4].*-*}
USE_BUILTIN.curses=	no
.      endif
.    else
USE_BUILTIN.curses=	no
.    endif
.  endif
.endif

# Even if the package requested tests above pass,
# some system curses just are not good enough.
# If your system is one, add it here so a suitable
# curses from pkgsrc can be installed.
_INCOMPAT_CURSES?=
.for _pattern_ in ${_INCOMPAT_CURSES} ${INCOMPAT_CURSES}
.  if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.curses=	no
.  endif
.endfor

MAKEVARS+=	USE_BUILTIN.curses

# Define BUILTIN_LIBNAME.curses to be the base name of the built-in
# curses library.
#
.if ${BUILTIN_LIB_FOUND.curses:U:tl} == yes
BUILTIN_LIBNAME.curses=		curses
.endif

BUILTIN_LIBNAME.curses=		curses

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.curses?=	no
.if ${CHECK_BUILTIN.curses:tl} == no

.  if ${USE_BUILTIN.curses:tl} == yes
.    if exists(${TOOLS_CROSS_DESTDIR}${H_CURSES})
BUILDLINK_INCDIRS.curses?=	${H_CURSES:H}
.    endif
BUILDLINK_LIBNAME.curses=	${BUILTIN_LIBNAME.curses}
.  endif

.endif	# CHECK_BUILTIN.curses
