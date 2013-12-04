# $NetBSD: builtin.mk,v 1.10 2013/12/04 14:19:01 obache Exp $

BUILTIN_PKG:=	zlib

BUILTIN_FIND_HEADERS_VAR:=	H_ZLIB
BUILTIN_FIND_HEADERS.H_ZLIB=	zlib.h

.include "../../mk/buildlink3/bsd.builtin.mk"

.if ! empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
USE_BUILTIN.zlib=no
.endif

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.zlib)
IS_BUILTIN.zlib=	no
.  if empty(H_ZLIB:M__nonexistent__) && empty(H_ZLIB:M${LOCALBASE}/*)
IS_BUILTIN.zlib=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.zlib

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.zlib) && \
    !empty(IS_BUILTIN.zlib:M[yY][eE][sS]) && \
    empty(H_ZLIB:M__nonexistent__)
BUILTIN_VERSION.zlib!=							\
	${AWK} '/\#define[ 	]*ZLIB_VERSION/ {			\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${H_ZLIB:Q}
BUILTIN_PKG.zlib=	zlib-${BUILTIN_VERSION.zlib}
.endif
MAKEVARS+=	BUILTIN_PKG.zlib

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.zlib)
.  if ${PREFER.zlib} == "pkgsrc"
USE_BUILTIN.zlib=	no
.  else
USE_BUILTIN.zlib=	${IS_BUILTIN.zlib}
.    if defined(BUILTIN_PKG.zlib) && \
        !empty(IS_BUILTIN.zlib:M[yY][eE][sS])
USE_BUILTIN.zlib=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.zlib}
.        if !empty(USE_BUILTIN.zlib:M[yY][eE][sS])
USE_BUILTIN.zlib!=	\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.zlib:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.zlib
.endif
MAKEVARS+=	USE_BUILTIN.zlib

# If USE_ZLIB is defined, then force the use of a true zlib
# implementation.
#
.if defined(USE_ZLIB)
.  if !empty(IS_BUILTIN.zlib:M[nN][oO])
USE_BUILTIN.zlib=	no
.  endif
.endif
