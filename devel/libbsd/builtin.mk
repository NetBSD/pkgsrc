# $NetBSD: builtin.mk,v 1.3 2023/08/29 16:25:59 vins Exp $

BUILTIN_PKG:=	libbsd

BUILTIN_FIND_HEADERS_VAR:=	H_LIBBSD
BUILTIN_FIND_HEADERS.H_LIBBSD=	bsd/bsd.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libbsd)
IS_BUILTIN.libbsd=	no
.  if empty(H_LIBBSD:M__nonexistent__) && empty(H_LIBBSD:M${LOCALBASE}/*)
IS_BUILTIN.libbsd=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libbsd

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libbsd)
.  if ${PREFER.libbsd} == "pkgsrc"
USE_BUILTIN.libbsd=	no
.  else
USE_BUILTIN.libbsd=	${IS_BUILTIN.libbsd}
.    if defined(BUILTIN_PKG.libbsd) && \
        ${IS_BUILTIN.libbsd:tl} == yes
USE_BUILTIN.libbsd=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libbsd}
.        if ${USE_BUILTIN.libbsd:tl} == yes
USE_BUILTIN.libbsd!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libbsd:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libbsd
.endif
MAKEVARS+=		USE_BUILTIN.libbsd
