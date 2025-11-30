# $NetBSD: builtin.mk,v 1.3 2025/11/30 19:17:09 vins Exp $

BUILTIN_PKG:=	libtirpc

BUILTIN_FIND_LIBS:=		tirpc
BUILTIN_FIND_HEADERS_VAR:=	H_TIRPC H_RPC

BUILTIN_FIND_HEADERS.H_RPC=	rpc/rpc.h
BUILTIN_FIND_HEADERS.H_TIRPC=	tirpc/rpc/rpc.h
BUILTIN_FIND_GREP.H_RPC=	\#define[       ]*_RPC_RPC_H
BUILTIN_FIND_GREP.H_TIRPC=	\#define[       ]*_TIRPC_RPC_H

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.rpc)
IS_BUILTIN.libtirpc=	no
.  if empty(H_TIRPC:M__nonexistent__) && \
	!empty(BUILTIN_LIB_FOUND.tirpc:M[yY][eE][sS])
IS_BUILTIN.libtirpc=	yes
.  elif empty(H_RPC:M__nonexistent__)
IS_BUILTIN.libtirpc=	yes
.  else
IS_BUILTIN.libtirpc=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libtirpc

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
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libtirpc}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif		# PREFER.libtirpc
.endif
MAKEVARS+=		USE_BUILTIN.libtirpc
