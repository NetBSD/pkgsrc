# $NetBSD: builtin.mk,v 1.3 2009/03/06 16:22:55 abs Exp $

BUILTIN_PKG:=	sun-jdk6

BUILTIN_FIND_FILES_VAR:=	JDK6
BUILTIN_FIND_FILES.JDK6=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.6/Commands/javac\
	/usr/jdk/instances/jdk1.6.0/bin/javac

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jdk6)
.  if empty(JDK6:M__nonexistent__)
IS_BUILTIN.sun-jdk6=	yes
.  else
IS_BUILTIN.sun-jdk6=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jdk6

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jdk6) && \
    !empty(IS_BUILTIN.sun-jdk6:M[yY][eE][sS]) && \
    empty(JDK6:M__nonexistent__)

BUILTIN_VERSION.sun-jdk6!= ${JDK6} -version 2>&1 | ${HEAD} -1 | \
	${AWK} '{print $$2}'

BUILTIN_PKG.sun-jdk6=	sun-jdk6-${BUILTIN_VERSION.sun-jdk6}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jdk6

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jdk6)
.  if ${PREFER.sun-jdk6} == "pkgsrc"
USE_BUILTIN.sun-jdk6=	no
.  else
USE_BUILTIN.sun-jdk6=	${IS_BUILTIN.sun-jdk6}
.    if defined(BUILTIN_PKG.sun-jdk6) && \
        !empty(IS_BUILTIN.sun-jdk6:M[yY][eE][sS])
USE_BUILTIN.sun-jdk6=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jdk6}
.        if !empty(USE_BUILTIN.sun-jdk6:M[yY][eE][sS])
USE_BUILTIN.sun-jdk6!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jdk6:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jdk6
.endif
