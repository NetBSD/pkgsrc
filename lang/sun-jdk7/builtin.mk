# $NetBSD: builtin.mk,v 1.1 2012/12/11 14:51:33 ryoon Exp $

BUILTIN_PKG:=	sun-jdk7

BUILTIN_FIND_FILES_VAR:=	JDK7
BUILTIN_FIND_FILES.JDK7=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.7/Commands/javac\
	/usr/jdk/instances/jdk1.7.0/bin/javac

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jdk7)
.  if empty(JDK7:M__nonexistent__)
IS_BUILTIN.sun-jdk7=	yes
.  else
IS_BUILTIN.sun-jdk7=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jdk7

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jdk7) && \
    !empty(IS_BUILTIN.sun-jdk7:M[yY][eE][sS]) && \
    empty(JDK7:M__nonexistent__)

BUILTIN_VERSION.sun-jdk7!= ${JDK7} -version 2>&1 | ${HEAD} -1 | \
	${AWK} '{print $$2}'

BUILTIN_PKG.sun-jdk7=	sun-jdk7-${BUILTIN_VERSION.sun-jdk7}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jdk7

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jdk7)
.  if ${PREFER.sun-jdk7} == "pkgsrc"
USE_BUILTIN.sun-jdk7=	no
.  else
USE_BUILTIN.sun-jdk7=	${IS_BUILTIN.sun-jdk7}
.    if defined(BUILTIN_PKG.sun-jdk7) && \
        !empty(IS_BUILTIN.sun-jdk7:M[yY][eE][sS])
USE_BUILTIN.sun-jdk7=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jdk7}
.        if !empty(USE_BUILTIN.sun-jdk7:M[yY][eE][sS])
USE_BUILTIN.sun-jdk7!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jdk7:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jdk7
.endif
