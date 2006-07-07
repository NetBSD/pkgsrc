# $NetBSD: builtin.mk,v 1.1 2006/07/07 02:58:20 minskim Exp $

BUILTIN_PKG:=	sun-jre13

BUILTIN_FIND_FILES_VAR:=		JAVAVM13
BUILTIN_FIND_FILES.JAVAVM13=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.3

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jre13)
.  if empty(JAVAVM13:M__nonexistent__)
IS_BUILTIN.sun-jre13=	yes
.  else
IS_BUILTIN.sun-jre13=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jre13

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jre13) && \
    !empty(IS_BUILTIN.sun-jre13:M[yY][eE][sS]) && \
    empty(JAVAVM13:M__nonexistent__)
BUILTIN_VERSION.sun-jre13!=						\
	${BASENAME} /System/Library/Frameworks/JavaVM.framework/Versions/1.3.* 
BUILTIN_PKG.sun-jre13=	sun-jre13-${BUILTIN_VERSION.sun-jre13}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jre13

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jre13)
.  if ${PREFER.sun-jre13} == "pkgsrc"
USE_BUILTIN.sun-jre13=	no
.  else
USE_BUILTIN.sun-jre13=	${IS_BUILTIN.sun-jre13}
.    if defined(BUILTIN_PKG.sun-jre13) && \
        !empty(IS_BUILTIN.sun-jre13:M[yY][eE][sS])
USE_BUILTIN.sun-jre13=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jre13}
.        if !empty(USE_BUILTIN.sun-jre13:M[yY][eE][sS])
USE_BUILTIN.sun-jre13!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jre13:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jre13
.endif
MAKEVARS+=	USE_BUILTIN.sun-jre13

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.sun-jre13?=	no
.if !empty(CHECK_BUILTIN.sun-jre13:M[nN][oO])
.  if !empty(USE_BUILTIN.sun-jre13:M[yY][eE][sS])
PKG_JAVA_HOME= \
	/System/Library/Frameworks/JavaVM.framework/Versions/1.3/Home
.  endif
.endif
