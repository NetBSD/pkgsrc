BUILTIN_PKG:=	openjdk7

BUILTIN_FIND_FILES_VAR:=	OJDK7
BUILTIN_FIND_FILES.OJDK7=	\
	/usr/lib64/jvm/java-1.7.0-openjdk-1.7.0/bin/javac

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.openjdk7)
.  if empty(OJDK7:M__nonexistent__)
IS_BUILTIN.openjdk7=	yes
.  else
IS_BUILTIN.openjdk7=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.openjdk7

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.openjdk7) && \
    !empty(IS_BUILTIN.openjdk7:M[yY][eE][sS])
BUILTIN_VERSION.openjdk7!=	${OJDK7} -version 2>&1 | ${SED} -Ee 's:^[^0-9]*([0-9._]+)$:\1:' -e 's/_/./g' -e 's/([0-9]+)\.([0-9]+)\.([0-9]+)\.([0-9]+)/\1.\2.\4/'
BUILTIN_PKG.openjdk7=	openjdk7-$(BUILTIN_VERSION.openjdk7)
.endif
MAKEVARS+=	BUILTIN_PKG.openjdk7

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.openjdk7)
.  if ${PREFER.openjdk7} == "pkgsrc"
USE_BUILTIN.openjdk7=	no
.  else
USE_BUILTIN.openjdk7=	${IS_BUILTIN.openjdk7}
.    if defined(BUILTIN_PKG.openjdk7) && \
	!empty(IS_BUILTIN.openjdk7:M[yY][eE][sS])
USE_BUILTIN.openjdk7=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.openjdk7}
.        if !empty(USE_BUILTIN.openjdk7:M[yY][eE][sS])
USE_BUILTIN.openjdk7!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.openjdk7:Q}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.openjdk7

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.openjdk7?=	no
.if !empty(CHECK_BUILTIN.openjdk7:M[nN][oO])
#
# Here we place code that depends on whether USE_BUILTIN.openjdk7 is
# set to "yes" or "no".
#
.  if !empty(USE_BUILTIN.openjdk7:M[yY][eE][sS])
PKG_JAVA_HOME=	${OJDK7:H:H}
.  endif
.endif  # CHECK_BUILTIN.openjdk7
