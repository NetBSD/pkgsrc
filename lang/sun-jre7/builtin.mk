# $NetBSD: builtin.mk,v 1.1 2012/12/11 14:47:17 ryoon Exp $

BUILTIN_PKG:=	sun-jre7

BUILTIN_FIND_FILES_VAR:=	JAVAVM7
BUILTIN_FIND_FILES.JAVAVM7=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.7/Home \
	/usr/jdk/instances/jdk1.7.0

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jre7)
.  if empty(JAVAVM7:M__nonexistent__)
IS_BUILTIN.sun-jre7=	yes
.  else
IS_BUILTIN.sun-jre7=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jre7

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jre7) && \
    !empty(IS_BUILTIN.sun-jre7:M[yY][eE][sS]) && \
    empty(JAVAVM7:M__nonexistent__)

BUILTIN_VERSION.sun-jre7!= ${JAVAVM7}/bin/java -version 2>&1 | ${HEAD} -1 | \
	${AWK} -F \" '{print $$2}' | ${AWK} -F _ '{print $$1}'

BUILTIN_PKG.sun-jre7=	sun-jre7-${BUILTIN_VERSION.sun-jre7}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jre7

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jre7)
.  if ${PREFER.sun-jre7} == "pkgsrc"
USE_BUILTIN.sun-jre7=	no
.  else
USE_BUILTIN.sun-jre7=	${IS_BUILTIN.sun-jre7}
.    if defined(BUILTIN_PKG.sun-jre7) && \
        !empty(IS_BUILTIN.sun-jre7:M[yY][eE][sS])
USE_BUILTIN.sun-jre7=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jre7}
.        if !empty(USE_BUILTIN.sun-jre7:M[yY][eE][sS])
USE_BUILTIN.sun-jre7!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jre7:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jre7
.endif
MAKEVARS+=	USE_BUILTIN.sun-jre7

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.sun-jre7?=	no
.if !empty(CHECK_BUILTIN.sun-jre7:M[nN][oO])
.  if !empty(USE_BUILTIN.sun-jre7:M[yY][eE][sS])
PKG_JAVA_HOME=	${JAVAVM7}
.  endif
.endif
