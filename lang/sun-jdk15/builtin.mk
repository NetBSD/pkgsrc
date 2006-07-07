# $NetBSD: builtin.mk,v 1.1 2006/07/07 04:42:59 minskim Exp $

BUILTIN_PKG:=	sun-jdk15

BUILTIN_FIND_FILES_VAR:=		JDK15
BUILTIN_FIND_FILES.JDK15=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.5/Commands/javac

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jdk15)
.  if empty(JDK15:M__nonexistent__)
IS_BUILTIN.sun-jdk15=	yes
.  else
IS_BUILTIN.sun-jdk15=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jdk15

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jdk15) && \
    !empty(IS_BUILTIN.sun-jdk15:M[yY][eE][sS]) && \
    empty(JDK15:M__nonexistent__)
BUILTIN_VERSION.sun-jdk15!=						\
	${BASENAME} /System/Library/Frameworks/JavaVM.framework/Versions/1.5.*
BUILTIN_PKG.sun-jdk15=	sun-jdk15-${BUILTIN_VERSION.sun-jdk15}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jdk15

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jdk15)
.  if ${PREFER.sun-jdk15} == "pkgsrc"
USE_BUILTIN.sun-jdk15=	no
.  else
USE_BUILTIN.sun-jdk15=	${IS_BUILTIN.sun-jdk15}
.    if defined(BUILTIN_PKG.sun-jdk15) && \
        !empty(IS_BUILTIN.sun-jdk15:M[yY][eE][sS])
USE_BUILTIN.sun-jdk15=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jdk15}
.        if !empty(USE_BUILTIN.sun-jdk15:M[yY][eE][sS])
USE_BUILTIN.sun-jdk15!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jdk15:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jdk15
.endif
