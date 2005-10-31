# $NetBSD: builtin.mk,v 1.1.1.1 2005/10/31 15:53:19 tv Exp $

BUILTIN_PKG:=	sysexits

BUILTIN_FIND_FILES_VAR:=	H_SYSEXITS
BUILTIN_FIND_FILES.H_SYSEXITS=	/usr/include/sysexits.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sysexits)
IS_BUILTIN.sysexits=	no
.  if empty(H_SYSEXITS:M${LOCALBASE}/*) && exists(${H_SYSEXITS})
IS_BUILTIN.sysexits=	yes
.  endif
.endif	# IS_BUILTIN.sysexits
MAKEVARS+=	IS_BUILTIN.sysexits

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sysexits)
.  if ${PREFER.sysexits} == "pkgsrc"
USE_BUILTIN.sysexits=	no
.  else
USE_BUILTIN.sysexits=	${IS_BUILTIN.sysexits}
.    if defined(BUILTIN_PKG.sysexits) && \
        !empty(IS_BUILTIN.sysexits:M[yY][eE][sS])
USE_BUILTIN.sysexits=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.sysexits}
.        if !empty(USE_BUILTIN.sysexits:M[yY][eE][sS])
USE_BUILTIN.sysexits!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sysexits:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sysexits
.endif
MAKEVARS+=	USE_BUILTIN.sysexits
