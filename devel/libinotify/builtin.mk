# $NetBSD: builtin.mk,v 1.3 2023/04/26 16:03:30 wiz Exp $

BUILTIN_PKG:=	libinotify

BUILTIN_FIND_HEADERS_VAR:=	H_INOTIFY
BUILTIN_FIND_HEADERS.H_INOTIFY=	sys/inotify.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libinotify)
IS_BUILTIN.libinotify=	no
.  if empty(H_INOTIFY:M__nonexistent__) && empty(H_INOTIFY:M${LOCALBASE}/*)
IS_BUILTIN.libinotify=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libinotify

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libinotify)
.  if ${PREFER.libinotify} == "pkgsrc"
USE_BUILTIN.libinotify=	no
.  else
USE_BUILTIN.libinotify=	${IS_BUILTIN.libinotify}
.    if defined(BUILTIN_PKG.libinotify) && \
        ${IS_BUILTIN.libinotify:tl} == yes
USE_BUILTIN.libinotify=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libinotify}
.        if ${USE_BUILTIN.libinotify:tl} == yes
USE_BUILTIN.libinotify!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libinotify:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libinotify
.endif
MAKEVARS+=		USE_BUILTIN.libinotify
