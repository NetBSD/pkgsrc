# $NetBSD: builtin.mk,v 1.7 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=	getopt

BUILTIN_FIND_HEADERS_VAR:=	H_GETOPT
BUILTIN_FIND_HEADERS.H_GETOPT=	getopt.h
BUILTIN_FIND_GREP.H_GETOPT=	int.*getopt_long

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.getopt)
IS_BUILTIN.getopt=	no
.  if empty(H_GETOPT:M__nonexistent__) && empty(H_GETOPT:M${LOCALBASE}/*)
IS_BUILTIN.getopt=	yes
.  endif
.endif	# IS_BUILTIN.getopt
MAKEVARS+=	IS_BUILTIN.getopt

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.getopt)
.  if ${PREFER.getopt} == "pkgsrc"
USE_BUILTIN.getopt=	no
.  else
USE_BUILTIN.getopt=	${IS_BUILTIN.getopt}
.    if defined(BUILTIN_PKG.getopt) && \
        !empty(IS_BUILTIN.getopt:M[yY][eE][sS])
USE_BUILTIN.getopt=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.getopt}
.        if !empty(USE_BUILTIN.getopt:M[yY][eE][sS])
USE_BUILTIN.getopt!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.getopt:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.getopt
.endif
MAKEVARS+=	USE_BUILTIN.getopt

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.getopt?=	no
.if !empty(CHECK_BUILTIN.getopt:M[nN][oO])

.  if !empty(USE_BUILTIN.getopt:M[nN][oO])
_BLTN_LIBGETOPT=	-lgetopt
.  else
_BLTN_LIBGETOPT=	# empty
.  endif
BUILDLINK_LDADD.getopt?=	${_BLTN_LIBGETOPT}

CONFIGURE_ENV+=		LIBGETOPT=${BUILDLINK_LDADD.getopt:Q}
MAKE_ENV+=		LIBGETOPT=${BUILDLINK_LDADD.getopt:Q}

.endif	# CHECK_BUILTIN.getopt
