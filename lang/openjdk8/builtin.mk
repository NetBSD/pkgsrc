# $NetBSD: builtin.mk,v 1.6 2023/02/27 11:09:40 jperkin Exp $

BUILTIN_PKG:=	openjdk8

BUILTIN_FIND_FILES_VAR:=	OJDK8
BUILTIN_FIND_FILES.OJDK8=	\
	/usr/lib64/jvm/java-1.8.0-openjdk-1.8.0/bin/javac	\
	/usr/lib/jvm/java-1.8.0-openjdk/bin/javac

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.openjdk8)
.  if empty(OJDK8:M__nonexistent__)
IS_BUILTIN.openjdk8=	yes
.  else
IS_BUILTIN.openjdk8=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.openjdk8

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.openjdk8) && \
    ${IS_BUILTIN.openjdk8:tl} == yes
BUILTIN_VERSION.openjdk8!=	${OJDK8} -version 2>&1 | ${SED} -Ee 's:^[^0-9]*([0-9._]+)$$:\1:' -e 's/_/./g' -e 's/([0-9]+)\.([0-9]+)\.([0-9]+)\.([0-9]+)/\1.\2.\4/'
BUILTIN_PKG.openjdk8=		openjdk8-${BUILTIN_VERSION.openjdk8}
.endif
MAKEVARS+=			BUILTIN_PKG.openjdk8

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.openjdk8)
.  if ${PREFER.openjdk8} == "pkgsrc"
USE_BUILTIN.openjdk8=	no
.  else
USE_BUILTIN.openjdk8=	${IS_BUILTIN.openjdk8}
.    if defined(BUILTIN_PKG.openjdk8) && \
	${IS_BUILTIN.openjdk8:tl} == yes
USE_BUILTIN.openjdk8=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.openjdk8}
.        if ${USE_BUILTIN.openjdk8:tl} == yes
USE_BUILTIN.openjdk8!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.openjdk8:Q}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=		USE_BUILTIN.openjdk8

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.openjdk8?=	no
.if ${CHECK_BUILTIN.openjdk8:tl} == no
#
# Here we place code that depends on whether USE_BUILTIN.openjdk8 is
# set to "yes" or "no".
#
.  if ${USE_BUILTIN.openjdk8:tl} == yes
PKG_JAVA_HOME=	${OJDK8:H:H}
.  endif
.endif  # CHECK_BUILTIN.openjdk8
