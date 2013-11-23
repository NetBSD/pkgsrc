# $NetBSD: solaris-pam.builtin.mk,v 1.5 2013/11/23 09:10:14 obache Exp $

BUILTIN_PKG:=	solaris-pam

BUILTIN_FIND_HEADERS_VAR:=		H_SOLARIS_PAM
BUILTIN_FIND_HEADERS.H_SOLARIS_PAM=	security/pam_appl.h
BUILTIN_FIND_GREP.H_SOLARIS_PAM=	Copyright.*Sun Microsystems

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.solaris-pam)
IS_BUILTIN.solaris-pam=	no
.  if empty(H_SOLARIS_PAM:M${LOCALBASE}/*) && exists(${H_SOLARIS_PAM})
IS_BUILTIN.solaris-pam=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.solaris-pam

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.solaris-pam)
.  if ${PREFER.solaris-pam} == "pkgsrc"
USE_BUILTIN.solaris-pam=	no
.  else
USE_BUILTIN.solaris-pam=	${IS_BUILTIN.solaris-pam}
.    if defined(BUILTIN_PKG.solaris-pam) && \
        !empty(IS_BUILTIN.solaris-pam:M[yY][eE][sS])
USE_BUILTIN.solaris-pam=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.solaris-pam}
.        if !empty(USE_BUILTIN.solaris-pam:M[yY][eE][sS])
USE_BUILTIN.solaris-pam!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.solaris-pam:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.solaris-pam
.endif
MAKEVARS+=	USE_BUILTIN.solaris-pam
