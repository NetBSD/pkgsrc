# $NetBSD: builtin.mk,v 1.4 2005/06/09 06:07:29 jlam Exp $

BUILTIN_PKG:=	openpam

BUILTIN_FIND_FILES_VAR:=	H_OPENPAM
BUILTIN_FIND_FILES.H_OPENPAM=	/usr/include/security/openpam_version.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.openpam)
IS_BUILTIN.openpam=	no
.  if empty(H_OPENPAM:M${LOCALBASE}/*) && exists(${H_OPENPAM})
IS_BUILTIN.openpam=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.openpam

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.openpam) && \
    !empty(IS_BUILTIN.openpam:M[yY][eE][sS]) && \
    exists(${H_OPENPAM})
BUILTIN_VERSION.openpam!=	\
	${AWK} '/\#define[ 	]*_OPENPAM_VERSION[ 	]/ {print $$3; }' \
		${H_OPENPAM}
BUILTIN_PKG.openpam=	openpam-${BUILTIN_VERSION.openpam}
.endif
MAKEVARS+=	BUILTIN_PKG.openpam

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.openpam)
.  if ${PREFER.openpam} == "pkgsrc"
USE_BUILTIN.openpam=	no
.  else
USE_BUILTIN.openpam=	${IS_BUILTIN.openpam}
.    if defined(BUILTIN_PKG.openpam) && \
        !empty(IS_BUILTIN.openpam:M[yY][eE][sS])
USE_BUILTIN.openpam=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.openpam}
.        if !empty(USE_BUILTIN.openpam:M[yY][eE][sS])
USE_BUILTIN.openpam!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.openpam:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.openpam
.endif
MAKEVARS+=	USE_BUILTIN.openpam
