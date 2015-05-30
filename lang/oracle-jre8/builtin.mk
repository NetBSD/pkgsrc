# $NetBSD: builtin.mk,v 1.1 2015/05/30 09:49:43 ryoon Exp $

BUILTIN_PKG:=	oracle-jre8

BUILTIN_FIND_FILES_VAR:=	JAVAVM8
BUILTIN_FIND_FILES.JAVAVM8=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.8/Home \
	/usr/jdk/instances/jdk1.8.0

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### On Darwin, if a suitable JRE has not already been found, try to find
### it in the standard JRE location.  Normally, we would just add the
### standard JRE location path to BUILTIN_FIND_FILES.JAVAVM8 above, but
### unfortunately, the path contains a space, and the BUILTIN_FIND_FILES
### "subroutine" can't handle paths containing whitespace (because it
### iterates over the paths in a for-loop).  So, we perform the check by
### hand.
###
.if ${OPSYS} == "Darwin" && \
    !empty(JAVAVM8:M__nonexistent__)
_JRE_HOME=	\
	/Library/Internet Plug-Ins/JavaAppletPlugin.plugin/Contents/Home
.  if exists(${_JRE_HOME})
JAVAVM8=	${_JRE_HOME}
.  endif
.endif

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.oracle-jre8)
.  if empty(JAVAVM8:M__nonexistent__)
IS_BUILTIN.oracle-jre8=	yes
.  else
IS_BUILTIN.oracle-jre8=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.oracle-jre8

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.oracle-jre8) && \
    !empty(IS_BUILTIN.oracle-jre8:M[yY][eE][sS]) && \
    empty(JAVAVM8:M__nonexistent__)

BUILTIN_VERSION.oracle-jre8!= ${JAVAVM8:Q}/bin/java -version 2>&1 | \
	${AWK} -F \" '{print $$2; exit}' | \
	${AWK} '{sub(/^1\./,"");sub(/_/,".");print $$1}'

BUILTIN_PKG.oracle-jre8=	oracle-jre8-${BUILTIN_VERSION.oracle-jre8}
.endif
MAKEVARS+=	BUILTIN_PKG.oracle-jre8

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.oracle-jre8)
.  if ${PREFER.oracle-jre8} == "pkgsrc"
USE_BUILTIN.oracle-jre8=	no
.  else
USE_BUILTIN.oracle-jre8=	${IS_BUILTIN.oracle-jre8}
.    if defined(BUILTIN_PKG.oracle-jre8) && \
        !empty(IS_BUILTIN.oracle-jre8:M[yY][eE][sS])
USE_BUILTIN.oracle-jre8=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.oracle-jre8}
.        if !empty(USE_BUILTIN.oracle-jre8:M[yY][eE][sS])
USE_BUILTIN.oracle-jre8!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.oracle-jre8:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.oracle-jre8
.endif
MAKEVARS+=	USE_BUILTIN.oracle-jre8

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.oracle-jre8?=	no
.if !empty(CHECK_BUILTIN.oracle-jre8:M[nN][oO])
.  if !empty(USE_BUILTIN.oracle-jre8:M[yY][eE][sS])
PKG_JAVA_HOME=	${JAVAVM8}
.  endif
.endif
