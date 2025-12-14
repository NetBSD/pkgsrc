# $NetBSD: builtin.mk,v 1.2 2025/12/14 19:02:51 vins Exp $

BUILTIN_PKG:=	sndio

BUILTIN_FIND_LIBS:=		sndio
BUILTIN_FIND_HEADERS_VAR:=	H_SNDIO

BUILTIN_FIND_HEADERS.H_SNDIO=	sndio.h
BUILTIN_FIND_GREP.H_SNDIO=	\#define[       ]*_SNDIO_H

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sndio)
IS_BUILTIN.sndio=	no
.  if empty(H_SNDIO:M__nonexistent__) && \
	!empty(BUILTIN_LIB_FOUND.sndio:M[yY][eE][sS])
IS_BUILTIN.sndio=	yes
.  else
IS_BUILTIN.sndio=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.sndio

###
### Determine whether we should use the built-in implementation.
###
.if !defined(USE_BUILTIN.sndio)
.  if ${PREFER.sndio} == "pkgsrc"
USE_BUILTIN.sndio=	no
.  else
USE_BUILTIN.sndio=	${IS_BUILTIN.sndio}
.    if defined(BUILTIN_PKG.sndio) && \
        ${IS_BUILTIN.sndio:tl} == yes
USE_BUILTIN.sndio=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sndio}
.        if ${USE_BUILTIN.sndio:tl} == yes
USE_BUILTIN.sndio!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sndio}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif		# PREFER.sndio
.endif
MAKEVARS+=		USE_BUILTIN.sndio
