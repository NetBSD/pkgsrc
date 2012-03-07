# $NetBSD: builtin.mk,v 1.1.1.1 2012/03/07 14:25:00 taca Exp $

BUILTIN_PKG:=	bind

BUILTIN_FIND_FILES_VAR:=	EXE_NAMED
BUILTIN_FIND_FILES.EXE_NAMED=	/usr/sbin/named
BUILTIN_FIND_LIBS:=		bind

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Figure out the version of BIND if an ISC BIND named exists on the
### system.
###
.if !defined(BUILTIN_VERSION.bind) && \
    empty(EXE_NAMED:M__nonexistent__) && \
    empty(EXE_NAMED:M${LOCALBASE}/*)
BUILTIN_VERSION.bind!=	\
	${EXE_NAMED} -v 2>/dev/null | ${HEAD} -1 |			\
	${AWK} 'BEGIN { v = "4.9.11"; }					\
		/^BIND / { v = $$2; sub("-.*", "", v); }		\
		/^named / { v = $$2; sub("-.*", "", v); }		\
		END { print v; }'
.endif
MAKEVARS+=	BUILTIN_VERSION.bind

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.bind)
IS_BUILTIN.bind=	no
.  if defined(BUILTIN_VERSION.bind)
IS_BUILTIN.bind=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.bind

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.bind) && \
    !empty(IS_BUILTIN.bind:M[yY][eE][sS]) && \
    defined(BUILTIN_VERSION.bind)
BUILTIN_PKG.bind=	bind-${BUILTIN_VERSION.bind}
.endif
MAKEVARS+=	BUILTIN_PKG.bind

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.bind)
.  if ${PREFER.bind} == "pkgsrc"
USE_BUILTIN.bind=	no
.  else
USE_BUILTIN.bind=	${IS_BUILTIN.bind}
.    if defined(BUILTIN_PKG.bind) && \
        !empty(IS_BUILTIN.bind:M[yY][eE][sS])
USE_BUILTIN.bind=	yes
.      for dep in ${BUILDLINK_API_DEPENDS.bind}
.        if !empty(USE_BUILTIN.bind:M[yY][eE][sS])
USE_BUILTIN.bind!=							\
	if ${PKG_ADMIN} pmatch ${dep:Q} ${BUILTIN_PKG.bind:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.bind
.endif
MAKEVARS+=	USE_BUILTIN.bind

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.bind?=   no
.if !empty(CHECK_BUILTIN.bind:M[nN][oO])

.  if !empty(USE_BUILTIN.bind:M[yY][eE][sS])
.    if !empty(BUILTIN_LIB_FOUND.bind:M[yY][eE][sS])
BUILDLINK_LDADD.bind?=	-lbind
.    endif
.  elif !empty(USE_BUILTIN.bind:M[nN][oO])
BUILDLINK_LDADD.bind?=	-lbind
.  endif

.endif	# CHECK_BUILTIN.bind
