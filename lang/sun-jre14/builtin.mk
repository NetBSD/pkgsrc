# $NetBSD: builtin.mk,v 1.3 2007/02/22 19:01:21 wiz Exp $

BUILTIN_PKG:=	sun-jre14

BUILTIN_FIND_FILES_VAR:=		JAVAVM14
BUILTIN_FIND_FILES.JAVAVM14=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.4

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jre14)
.  if empty(JAVAVM14:M__nonexistent__)
IS_BUILTIN.sun-jre14=	yes
.  else
IS_BUILTIN.sun-jre14=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jre14

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jre14) && \
    !empty(IS_BUILTIN.sun-jre14:M[yY][eE][sS]) && \
    empty(JAVAVM14:M__nonexistent__)
BUILTIN_VERSION.sun-jre14!=						\
	${BASENAME} /System/Library/Frameworks/JavaVM.framework/Versions/1.4.*
BUILTIN_PKG.sun-jre14=	sun-jre14-${BUILTIN_VERSION.sun-jre14}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jre14

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jre14)
.  if ${PREFER.sun-jre14} == "pkgsrc"
USE_BUILTIN.sun-jre14=	no
.  else
USE_BUILTIN.sun-jre14=	${IS_BUILTIN.sun-jre14}
.    if defined(BUILTIN_PKG.sun-jre14) && \
        !empty(IS_BUILTIN.sun-jre14:M[yY][eE][sS])
USE_BUILTIN.sun-jre14=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jre14}
.        if !empty(USE_BUILTIN.sun-jre14:M[yY][eE][sS])
USE_BUILTIN.sun-jre14!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jre14:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jre14
.endif
MAKEVARS+=	USE_BUILTIN.sun-jre14

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.sun-jre14?=	no
.if !empty(CHECK_BUILTIN.sun-jre14:M[nN][oO])
.  if !empty(USE_BUILTIN.sun-jre14:M[yY][eE][sS])
PKG_JAVA_HOME= \
	/System/Library/Frameworks/JavaVM.framework/Versions/1.4/Home
.  endif
.endif
