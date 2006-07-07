# $NetBSD: builtin.mk,v 1.1 2006/07/07 04:42:59 minskim Exp $

BUILTIN_PKG:=	sun-jdk13

BUILTIN_FIND_FILES_VAR:=		jdk13
BUILTIN_FIND_FILES.jdk13=	\
	/System/Library/Frameworks/JavaVM.framework/Versions/1.3/Commands/javac

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.sun-jdk13)
.  if empty(jdk13:M__nonexistent__)
IS_BUILTIN.sun-jdk13=	yes
.  else
IS_BUILTIN.sun-jdk13=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.sun-jdk13

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.sun-jdk13) && \
    !empty(IS_BUILTIN.sun-jdk13:M[yY][eE][sS]) && \
    empty(jdk13:M__nonexistent__)
BUILTIN_VERSION.sun-jdk13!=						\
	${BASENAME} /System/Library/Frameworks/JavaVM.framework/Versions/1.3.*
BUILTIN_PKG.sun-jdk13=	sun-jdk13-${BUILTIN_VERSION.sun-jdk13}
.endif
MAKEVARS+=	BUILTIN_PKG.sun-jdk13

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.sun-jdk13)
.  if ${PREFER.sun-jdk13} == "pkgsrc"
USE_BUILTIN.sun-jdk13=	no
.  else
USE_BUILTIN.sun-jdk13=	${IS_BUILTIN.sun-jdk13}
.    if defined(BUILTIN_PKG.sun-jdk13) && \
        !empty(IS_BUILTIN.sun-jdk13:M[yY][eE][sS])
USE_BUILTIN.sun-jdk13=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.sun-jdk13}
.        if !empty(USE_BUILTIN.sun-jdk13:M[yY][eE][sS])
USE_BUILTIN.sun-jdk13!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.sun-jdk13:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.sun-jdk13
.endif
