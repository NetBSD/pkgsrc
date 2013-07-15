# $NetBSD: builtin.mk,v 1.1 2013/07/15 01:42:47 ryoon Exp $

BUILTIN_PKG:=	editline

BUILTIN_FIND_LIBS:=		edit
BUILTIN_FIND_FILES_VAR:=	H_EDITLINE
BUILTIN_FIND_FILES.H_EDITLINE=	/usr/include/readline/readline.h

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
# XXX
# XXX By default, assume that the native editline library is good enough
# XXX to replace GNU readline if it provides the readline-compatibility
# XXX headers.
# XXX
.    if !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS]) && \
	empty(H_EDITLINE:M__nonexistent__)
USE_BUILTIN.editline=	yes
.    endif
MAKEVARS+=	USE_BUILTIN.readline

BUILDLINK_TRANSFORM+=	l:history:edit:${BUILTIN_LIBNAME.termcap}
BUILDLINK_TRANSFORM+=	l:readline:edit:${BUILTIN_LIBNAME.termcap}
.endif

.endif	# CHECK_BUILTIN.readline
