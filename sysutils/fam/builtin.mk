# $NetBSD: builtin.mk,v 1.5 2013/11/23 12:10:13 obache Exp $

BUILTIN_PKG:=	fam

BUILTIN_FIND_HEADERS_VAR:=	H_FAM
BUILTIN_FIND_HEADERS.H_FAM=	fam.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.fam)
IS_BUILTIN.fam=	no
.  if empty(H_FAM:M__nonexistent__) && empty(H_FAM:M${LOCALBASE}/*)
IS_BUILTIN.fam=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.fam

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.fam)
.  if ${PREFER.fam} == "pkgsrc"
USE_BUILTIN.fam=	no
.  else
USE_BUILTIN.fam=	${IS_BUILTIN.fam}
.    if defined(BUILTIN_PKG.fam) && \
        !empty(IS_BUILTIN.fam:M[yY][eE][sS])
USE_BUILTIN.fam=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.fam}
.        if !empty(USE_BUILTIN.fam:M[yY][eE][sS])
USE_BUILTIN.fam!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.fam:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.fam
.endif
MAKEVARS+=	USE_BUILTIN.fam
