# $NetBSD: builtin.mk,v 1.1 2006/07/07 04:42:59 minskim Exp $

BUILTIN_PKG:=	sun-jdk14

BUILTIN_FIND_FILES_VAR:=		jdk14
BUILTIN_FIND_FILES.jdk14=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.4/Commands/javac

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jdk14)
.  if empty(jdk14:M__nonexistent__)
IS_BUILTIN.sun-jdk14=	yes
.  else
IS_BUILTIN.sun-jdk14=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jdk14

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jdk14) && \
    !empty(IS_BUILTIN.sun-jdk14:M[yY][eE][sS]) && \
    empty(jdk14:M__nonexistent__)
BUILTIN_VERSION.sun-jdk14!=						\
	${BASENAME} /System/Library/Frameworks/JavaVM.framework/Versions/1.4.*
BUILTIN_PKG.sun-jdk14=	sun-jdk14-${BUILTIN_VERSION.sun-jdk14}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jdk14

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jdk14)
.  if ${PREFER.sun-jdk14} == "pkgsrc"
USE_BUILTIN.sun-jdk14=	no
.  else
USE_BUILTIN.sun-jdk14=	${IS_BUILTIN.sun-jdk14}
.    if defined(BUILTIN_PKG.sun-jdk14) && \
        !empty(IS_BUILTIN.sun-jdk14:M[yY][eE][sS])
USE_BUILTIN.sun-jdk14=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jdk14}
.        if !empty(USE_BUILTIN.sun-jdk14:M[yY][eE][sS])
USE_BUILTIN.sun-jdk14!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jdk14:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jdk14
.endif
