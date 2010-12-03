# $NetBSD: builtin.mk,v 1.1 2010/12/03 10:15:55 wiz Exp $

BUILTIN_PKG:=	perfuse

BUILTIN_FIND_FILES_VAR:=	H_PERFUSE
BUILTIN_FIND_FILES.H_PERFUSE=	/usr/include/perfuse.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.perfuse)
IS_BUILTIN.perfuse=	no
.  if empty(H_PERFUSE:M__nonexistent__)
IS_BUILTIN.perfuse=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.perfuse

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.perfuse)
.  if ${PREFER.perfuse} == "pkgsrc"
USE_BUILTIN.perfuse=	no
.  else
USE_BUILTIN.perfuse=	${IS_BUILTIN.perfuse}
.    if defined(BUILTIN_PKG.perfuse) && \
        !empty(IS_BUILTIN.perfuse:M[yY][eE][sS])
USE_BUILTIN.perfuse=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.perfuse}
.        if !empty(USE_BUILTIN.perfuse:M[yY][eE][sS])
USE_BUILTIN.perfuse!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.perfuse:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.perfuse
.endif
MAKEVARS+=	USE_BUILTIN.perfuse
