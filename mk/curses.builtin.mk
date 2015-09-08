# $NetBSD: curses.builtin.mk,v 1.9 2015/09/08 11:36:34 jperkin Exp $

BUILTIN_PKG:=	curses

BUILTIN_FIND_LIBS:=		curses
BUILTIN_FIND_HEADERS_VAR:=	H_CURSES
BUILTIN_FIND_HEADERS.H_CURSES=	curses.h

BUILTIN_FIND_FILES_VAR+=	 H_CURSES_HALFDELAY
BUILTIN_FIND_FILES.H_CURSES_HALFDELAY=	${BUILTIN_FIND_FILES.H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_HALFDELAY=	halfdelay

BUILTIN_FIND_FILES_VAR+=	 H_CURSES_RESIZETERM
BUILTIN_FIND_FILES.H_CURSES_RESIZETERM=	${BUILTIN_FIND_FILES.H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_RESIZETERM=	resizeterm

BUILTIN_FIND_FILES_VAR+=	 H_CURSES_PUTWIN
BUILTIN_FIND_FILES.H_CURSES_PUTWIN=	${BUILTIN_FIND_FILES.H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_PUTWIN=	putwin

BUILTIN_FIND_FILES_VAR+=	 H_CURSES_WA_NORMAL
BUILTIN_FIND_FILES.H_CURSES_WA_NORMAL=	${BUILTIN_FIND_FILES.H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_WA_NORMAL=	WA_NORMAL

BUILTIN_FIND_FILES_VAR+=	 H_CURSES_WGETNSTR
BUILTIN_FIND_FILES.H_CURSES_WGETNSTR=	${BUILTIN_FIND_FILES.H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_WGETNSTR=	wgetnstr

BUILTIN_FIND_FILES_VAR+=	 H_CURSES_WSYNCUP
BUILTIN_FIND_FILES.H_CURSES_WSYNCUP=	${BUILTIN_FIND_FILES.H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_WSYNCUP=	wsyncup

BUILTIN_FIND_FILES_VAR+=	 H_CURSES_MVWCHGAT
BUILTIN_FIND_FILES.H_CURSES_MVWCHGAT=	${BUILTIN_FIND_FILES.H_CURSES}
BUILTIN_FIND_GREP.H_CURSES_MVWCHGAT=	mvwchgat

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.curses)
IS_BUILTIN.curses=	no
.  if empty(H_CURSES:M${LOCALBASE}/*) && exists(${H_CURSES})
IS_BUILTIN.curses=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.curses

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.curses)
.  if ${PREFER.curses} == "pkgsrc"
USE_BUILTIN.curses=	no
.  else
USE_BUILTIN.curses=	${IS_BUILTIN.curses}
.    if defined(BUILTIN_PKG.curses) && !empty(IS_BUILTIN.curses:M[yY][eE][sS])
USE_BUILTIN.curses=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.curses}
.        if !empty(USE_BUILTIN.curses:M[yY][eE][sS])
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
.if defined(USE_CURSES) && empty(USE_CURSES:M[yY][eE][sS])
.  if !empty(USE_CURSES:Mchgat) && !empty(H_CURSES_MVWCHGAT:M__nonexistent__)
USE_BUILTIN.curses=	no
.  endif
# same for halfdelay(3)
.  if !empty(USE_CURSES:Mhalfdelay)
.    if !empty(H_CURSES_HALFDELAY:M__nonexistent__)
USE_BUILTIN.curses=	no
.    endif
.  endif
## same for putwin(3)
.  if !empty(USE_CURSES:Mputwin) && !empty(H_CURSES_PUTWIN:M__nonexistent__)
USE_BUILTIN.curses=	no
.  endif
# same for resizeterm(3)
.  if !empty(USE_CURSES:Mresizeterm)
.    if !empty(H_CURSES_RESIZETERM:M__nonexistent__)
USE_BUILTIN.curses=	no
.    endif
.  endif
## same for WA_NORMAL
.  if !empty(USE_CURSES:MWA_NORMAL)
.    if !empty(H_CURSES_WA_NORMAL:M__nonexistent__)
USE_BUILTIN.curses=	no
.    endif
.  endif
## same for wgetnstr(3)
.  if !empty(USE_CURSES:Mwgetnstr) && !empty(H_CURSES_WGETNSTR:M__nonexistent__)
USE_BUILTIN.curses=	no
.  endif
# same for wsyncup(3)
.  if !empty(USE_CURSES:Mwsyncup) && !empty(H_CURSES_WSYNCUP:M__nonexistent__)
USE_BUILTIN.curses=	no
.  endif
# AFAIK there is no way of working out if a system curses library has wide
# character support. So be safe and say no unless we know for sure.
.  if !empty(USE_CURSES:Mwide)
.    if ${OPSYS} == "NetBSD"
.      if !empty(MACHINE_PLATFORM:MNetBSD-[0-4].*-*)
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
.if !empty(BUILTIN_LIB_FOUND.curses:M[yY][eE][sS])
BUILTIN_LIBNAME.curses=		curses
.endif

BUILTIN_LIBNAME.curses=		curses

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.curses?=	no
.if !empty(CHECK_BUILTIN.curses:M[nN][oO])

.  if !empty(USE_BUILTIN.curses:M[yY][eE][sS])
.    if exists(${H_CURSES})
BUILDLINK_INCDIRS.curses?=	${H_CURSES:H:S/^${BUILDLINK_PREFIX.curses}\///}
.    endif
BUILDLINK_LIBNAME.curses=	${BUILTIN_LIBNAME.curses}
.  endif

.endif	# CHECK_BUILTIN.curses
