# $NetBSD: builtin.mk,v 1.3 2005/06/01 18:02:44 jlam Exp $

BUILTIN_PKG:=	libevent

BUILTIN_FIND_FILES_VAR:=	H_LIBEVENT
BUILTIN_FIND_FILES.H_LIBEVENT=	/usr/include/event.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libevent)
IS_BUILTIN.libevent=	no
.  if empty(H_LIBEVENT:M${LOCALBASE}/*) && exists(${H_LIBEVENT})
IS_BUILTIN.libevent=	yes
.  endif
.endif	# IS_BUILTIN.libevent
MAKEVARS+=	IS_BUILTIN.libevent

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libevent)
.  if ${PREFER.libevent} == "pkgsrc"
USE_BUILTIN.libevent=	no
.  else
USE_BUILTIN.libevent=	${IS_BUILTIN.libevent}
.    if defined(BUILTIN_PKG.libevent) && \
        !empty(IS_BUILTIN.libevent:M[yY][eE][sS])
USE_BUILTIN.libevent=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.libevent}
.        if !empty(USE_BUILTIN.libevent:M[yY][eE][sS])
USE_BUILTIN.libevent!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libevent:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libevent
.endif
MAKEVARS+=	USE_BUILTIN.libevent
