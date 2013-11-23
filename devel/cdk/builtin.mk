# $NetBSD: builtin.mk,v 1.5 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=	cdk

BUILTIN_FIND_HEADERS_VAR:=	H_CDK
BUILTIN_FIND_HEADERS.H_CDK=	cdk/cdk.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.cdk)
IS_BUILTIN.cdk=	no
.  if empty(H_CDK:M__nonexistent__) && empty(H_CDK:M${LOCALBASE}/*)
IS_BUILTIN.cdk=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.cdk

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.cdk)
.  if ${PREFER.cdk} == "pkgsrc"
USE_BUILTIN.cdk=	no
.  else
USE_BUILTIN.cdk=	${IS_BUILTIN.cdk}
.    if defined(BUILTIN_PKG.cdk) && \
        !empty(IS_BUILTIN.cdk:M[yY][eE][sS])
USE_BUILTIN.cdk=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.cdk}
.        if !empty(USE_BUILTIN.cdk:M[yY][eE][sS])
USE_BUILTIN.cdk!=							\
        if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.cdk:Q}; then	\
		${ECHO} yes;						\
        else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.cdk
.endif
MAKEVARS+=	USE_BUILTIN.cdk
