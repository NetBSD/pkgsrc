# $NetBSD: builtin.mk,v 1.1 2023/08/29 11:28:40 vins Exp $

BUILTIN_PKG:=	libtirpc

BUILTIN_FIND_HEADERS_VAR:=		H_LIBTIRPC
BUILTIN_FIND_HEADERS.H_LIBTIRPC=	rpc/rpc.h
BUILTIN_FIND_GREP.H_LIBTIRPC=		\#define[ 	]*_TIRPC_RPC_H

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libtirpc)
IS_BUILTIN.libtirpc=	no
.  if empty(H_LIBTIRPC:M__nonexistent__) && empty(H_LIBTIRPC:M${LOCALBASE}/*)
IS_BUILTIN.libtirpc=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libtirpc

###
### Determine whether we should use the built-in implementation.
###
.if !defined(USE_BUILTIN.libtirpc)
.  if ${PREFER.libtirpc} == "pkgsrc"
USE_BUILTIN.libtirpc=	no
.  else
USE_BUILTIN.libtirpc=	${IS_BUILTIN.libtirpc}
.    if defined(BUILTIN_PKG.libtirpc) && \
        ${IS_BUILTIN.libtirpc:tl} == yes
USE_BUILTIN.libtirpc=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libtirpc}
.        if ${USE_BUILTIN.libtirpc:tl} == yes
USE_BUILTIN.libtirpc!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libtirpc:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libtirpc
.endif
MAKEVARS+=		USE_BUILTIN.libtirpc
