# $NetBSD: builtin.mk,v 1.2 2006/06/08 21:21:21 rillig Exp $

BUILTIN_PKG:=	sun-jre15

BUILTIN_FIND_FILES_VAR:=		JAVAVM15
BUILTIN_FIND_FILES.JAVAVM15=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.5

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jre15)
.  if empty(JAVAVM15:M__nonexistent__)
IS_BUILTIN.sun-jre15=	yes
.  else
IS_BUILTIN.sun-jre15=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jre15

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jre15) && \
    !empty(IS_BUILTIN.sun-jre15:M[yY][eE][sS]) && \
    empty(JAVAVM15:M__nonexistent__)
BUILTIN_VERSION.sun-jre15!=						\
	${BASENAME} /System/Library/Frameworks/JavaVM.framework/Versions/1.5.*
BUILTIN_PKG.sun-jre15=	sun-jre15-${BUILTIN_VERSION.sun-jre15}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jre15

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jre15)
.  if ${PREFER.sun-jre15} == "pkgsrc"
USE_BUILTIN.sun-jre15=	no
.  else
USE_BUILTIN.sun-jre15=	${IS_BUILTIN.sun-jre15}
.    if defined(BUILTIN_PKG.sun-jre15) && \
        !empty(IS_BUILTIN.sun-jre15:M[yY][eE][sS])
USE_BUILTIN.sun-jre15=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jre15}
.        if !empty(USE_BUILTIN.sun-jre15:M[yY][eE][sS])
USE_BUILTIN.sun-jre15!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jre15:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jre15
.endif
MAKEVARS+=	USE_BUILTIN.sun-jre15

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.sun-jre15?=	no
.if !empty(CHECK_BUILTIN.sun-jre15:M[nN][oO])
.  if !empty(USE_BUILTIN.sun-jre15:M[yY][eE][sS])
PKG_JAVA_BINDIR= \
	/System/Library/Frameworks/JavaVM.framework/Versions/1.5/Commands
.  endif
.endif
