# $NetBSD: builtin.mk,v 1.3 2005/06/01 18:02:59 jlam Exp $

BUILTIN_PKG:=	libmilter

BUILTIN_FIND_LIBS:=		milter
BUILTIN_FIND_FILES_VAR:=	H_LIBMILTER
BUILTIN_FIND_FILES.H_LIBMILTER=	/usr/include/libmilter/mfapi.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libmilter)
IS_BUILTIN.libmilter=	no
.  if empty(H_LIBMILTER:M${LOCALBASE}/*) && exists(${H_LIBMILTER}) && \
      !empty(BUILTIN_LIB_FOUND.milter:M[yY][eE][sS])
IS_BUILTIN.libmilter=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libmilter

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libmilter)
.  if ${PREFER.libmilter} == "pkgsrc"
USE_BUILTIN.libmilter=	no
.  else
USE_BUILTIN.libmilter=	${IS_BUILTIN.libmilter}
.    if defined(BUILTIN_PKG.libmilter) && \
        !empty(IS_BUILTIN.libmilter:M[yY][eE][sS])
USE_BUILTIN.libmilter=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.libmilter}
.        if !empty(USE_BUILTIN.libmilter:M[yY][eE][sS])
USE_BUILTIN.libmilter!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libmilter:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libmilter
.endif
MAKEVARS+=	USE_BUILTIN.libmilter
