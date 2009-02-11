# $NetBSD: builtin.mk,v 1.4 2009/02/11 21:20:46 adrianp Exp $

BUILTIN_PKG:=	sun-jre6

BUILTIN_FIND_FILES_VAR:=	JAVAVM6
BUILTIN_FIND_FILES.JAVAVM6=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.6/Home \
	/usr/jdk/instances/jdk1.6.0

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jre6)
.  if empty(JAVAVM6:M__nonexistent__)
IS_BUILTIN.sun-jre6=	yes
.  else
IS_BUILTIN.sun-jre6=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jre6

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jre6) && \
    !empty(IS_BUILTIN.sun-jre6:M[yY][eE][sS]) && \
    empty(JAVAVM6:M__nonexistent__)

BUILTIN_VERSION.sun-jre6!= ${JAVAVM6}/bin/java -version 2>&1 | ${HEAD} -1 | \
	${AWK} -F \" '{print $$2}' | ${AWK} -F _ '{print $$1}'

BUILTIN_PKG.sun-jre6=	sun-jre6-${BUILTIN_VERSION.sun-jre6}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jre6

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jre6)
.  if ${PREFER.sun-jre6} == "pkgsrc"
USE_BUILTIN.sun-jre6=	no
.  else
USE_BUILTIN.sun-jre6=	${IS_BUILTIN.sun-jre6}
.    if defined(BUILTIN_PKG.sun-jre6) && \
        !empty(IS_BUILTIN.sun-jre6:M[yY][eE][sS])
USE_BUILTIN.sun-jre6=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jre6}
.        if !empty(USE_BUILTIN.sun-jre6:M[yY][eE][sS])
USE_BUILTIN.sun-jre6!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jre6:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jre6
.endif
MAKEVARS+=	USE_BUILTIN.sun-jre6

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.sun-jre6?=	no
.if !empty(CHECK_BUILTIN.sun-jre6:M[nN][oO])
.  if !empty(USE_BUILTIN.sun-jre6:M[yY][eE][sS])
PKG_JAVA_HOME=	${JAVAVM6}
.  endif
.endif
