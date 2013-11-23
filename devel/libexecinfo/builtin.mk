# $NetBSD: builtin.mk,v 1.2 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=	libexecinfo

BUILTIN_FIND_HEADERS_VAR:=		H_EXECINFO
BUILTIN_FIND_HEADERS.H_EXECINFO=	execinfo.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libexecinfo)
IS_BUILTIN.libexecinfo=	no
.  if empty(H_EXECINFO:M__nonexistent__) && empty(H_EXECINFO:M${LOCALBASE}/*)
IS_BUILTIN.libexecinfo=	yes
.  endif
.endif	# IS_BUILTIN.libexecinfo
MAKEVARS+=	IS_BUILTIN.libexecinfo

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libexecinfo)
.  if ${PREFER.libexecinfo} == "pkgsrc"
USE_BUILTIN.libexecinfo=	no
.  else
USE_BUILTIN.libexecinfo=	${IS_BUILTIN.libexecinfo}
.    if defined(BUILTIN_PKG.libexecinfo) && \
        !empty(IS_BUILTIN.libexecinfo:M[yY][eE][sS])
USE_BUILTIN.libexecinfo=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libexecinfo}
.        if !empty(USE_BUILTIN.libexecinfo:M[yY][eE][sS])
USE_BUILTIN.libexecinfo!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libexecinfo:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libexecinfo
.endif
MAKEVARS+=	USE_BUILTIN.libexecinfo

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.libexecinfo?=	no
.if !empty(CHECK_BUILTIN.libexecinfo:M[nN][oO])

.  if !empty(USE_BUILTIN.libexecinfo:M[nN][oO])
_BLTN_LIBEXECINFO=	-lexecinfo
.  else
.    if exists(/usr/include/execinfo.h) && (${OPSYS} == "NetBSD")
_BLTN_LIBEXECINFO=	-lexecinfo
.    else
_BLTN_LIBEXECINFO=	# empty
.    endif
.  endif
BUILDLINK_LDADD.libexecinfo?=	${_BLTN_LIBEXECINFO}
BUILDLINK_LDFLAGS.libexecinfo?=	${_BLTN_LIBEXECINFO}

.endif	# CHECK_BUILTIN.libexecinfo
