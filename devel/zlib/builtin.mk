# $NetBSD: builtin.mk,v 1.3 2005/06/01 18:02:45 jlam Exp $

BUILTIN_PKG:=	zlib

BUILTIN_FIND_FILES_VAR:=	H_ZLIB
BUILTIN_FIND_FILES.H_ZLIB=	/usr/include/zlib.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.zlib)
IS_BUILTIN.zlib=	no
.  if empty(H_ZLIB:M${LOCALBASE}/*) && exists(${H_ZLIB})
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
    exists(${H_ZLIB})
BUILTIN_VERSION.zlib!=							\
	${AWK} '/\#define[ 	]*ZLIB_VERSION/ {			\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${H_ZLIB:Q}
#
# If the built-in zlib is 1.1.4, then check whether it has the security
# fix for CAN-2003-0107, which was a buffer overflow in the gzprintf
# function.  If it does, then treat it as the equivalent of zlib-1.1.4nb1.
#
BUILTIN_CAN_2003_0107_FIX=	NetBSD-1.3[I-Z]*-* NetBSD-1.[456]*-*	\
				NetBSD-[2-9]*-* NetBSD-1[0-9]*-*
#
# XXX These patterns for {Free,Open}BSD are too permissive, but I'm not
# XXX sure which versions of those OSes provide secure versions of
# XXX zlib-1.1.4.
#
BUILTIN_CAN_2003_0107_FIX+=	FreeBSD-*-* OpenBSD-*-*
.  if ${BUILTIN_VERSION.zlib} == "1.1.4"
.    for _pattern_ in ${BUILTIN_CAN_2003_0107_FIX}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILTIN_VERSION.zlib=	1.1.4nb1
.      endif
.    endfor
.  endif
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
.      for _dep_ in ${BUILDLINK_DEPENDS.zlib}
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
