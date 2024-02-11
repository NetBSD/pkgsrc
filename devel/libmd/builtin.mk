# $NetBSD: builtin.mk,v 1.2 2024/02/11 17:46:17 vins Exp $

BUILTIN_PKG:=	libmd

BUILTIN_FIND_HEADERS_VAR:=	H_LIBMD
BUILTIN_FIND_HEADERS.H_LIBMD=	sha.h
BUILTIN_FIND_GREP.H_LIBMD=	\#define[ 	]*LIBMD_SHA_H

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libmd)
IS_BUILTIN.libmd=	no
.  if empty(H_LIBMD:M__nonexistent__) && empty(H_LIBMD:M${LOCALBASE}/*)
IS_BUILTIN.libmd=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libmd

###
### Determine whether we should use the built-in implementation.
###
.if !defined(USE_BUILTIN.libmd)
.  if ${PREFER.libmd} == "pkgsrc"
USE_BUILTIN.libmd=	no
.  else
USE_BUILTIN.libmd=	${IS_BUILTIN.libmd}
.    if defined(BUILTIN_PKG.libmd) && \
        ${IS_BUILTIN.libmd:tl} == yes
USE_BUILTIN.libmd=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libmd}
.        if ${USE_BUILTIN.libmd:tl} == yes
USE_BUILTIN.libmd!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libmd:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libmd
.endif
MAKEVARS+=		USE_BUILTIN.libmd
