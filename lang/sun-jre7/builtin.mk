# $NetBSD: builtin.mk,v 1.3 2014/09/03 12:47:37 tron Exp $

BUILTIN_PKG:=	sun-jre7

BUILTIN_FIND_FILES_VAR:=	JAVAVM7
BUILTIN_FIND_FILES.JAVAVM7=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.7/Home \
	/usr/jdk/instances/jdk1.7.0

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### On Darwin, if a suitable JRE has not already been found, try to find
### it in the standard JRE location.  Normally, we would just add the
### standard JRE location path to BUILTIN_FIND_FILES.JAVAVM7 above, but
### unfortunately, the path contains a space, and the BUILTIN_FIND_FILES
### "subroutine" can't handle paths containing whitespace (because it
### iterates over the paths in a for-loop).  So, we perform the check by
### hand.
###
.if ${OPSYS} == "Darwin" && \
    !empty(JAVAVM7:M__nonexistent__)
_JRE_HOME=	\
	/Library/Internet Plug-Ins/JavaAppletPlugin.plugin/Contents/Home
.  if exists(${_JRE_HOME})
JAVAVM7=	${_JRE_HOME}
.  endif
.endif

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

BUILTIN_VERSION.sun-jre7!= ${JAVAVM7:Q}/bin/java -version 2>&1 | \
	${AWK} -F \" '{print $$2; exit}' | \
	${AWK} '{sub(/^1\./,"");sub(/_/,".");print $$1}'

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
