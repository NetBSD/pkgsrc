# $NetBSD: builtin.mk,v 1.5 2013/11/23 12:10:13 obache Exp $

BUILTIN_PKG:=	skey

BUILTIN_FIND_HEADERS_VAR:=	H_SKEY
BUILTIN_FIND_HEADERS.H_SKEY=	skey.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.skey)
IS_BUILTIN.skey=	no
.  if empty(H_SKEY:M__nonexistent__) && empty(H_SKEY:M${LOCALBASE}/*)
IS_BUILTIN.skey=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.skey

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.skey) && \
    !empty(IS_BUILTIN.skey:M[yY][eE][sS) && \
    empty(H_SKEY:M__nonexistent__)
# XXX
# XXX Consider the native skey to be skey-1.1.5.
# XXX
BUILTIN_PKG.skey=	skey-1.1.5
.endif
MAKEVARS+=	BUILTIN_PKG.skey

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.skey)
.  if ${PREFER.skey} == "pkgsrc"
USE_BUILTIN.skey=	no
.  else
USE_BUILTIN.skey=	${IS_BUILTIN.skey}
.    if defined(BUILTIN_PKG.skey) && \
        !empty(IS_BUILTIN.skey:M[yY][eE][sS])
USE_BUILTIN.skey=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.skey}
.        if !empty(USE_BUILTIN.skey:M[yY][eE][sS])
USE_BUILTIN.skey!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.skey:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.skey
.endif
MAKEVARS+=	USE_BUILTIN.skey
