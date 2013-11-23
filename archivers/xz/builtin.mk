# $NetBSD: builtin.mk,v 1.3 2013/11/23 10:51:09 obache Exp $

BUILTIN_PKG:=	xz

BUILTIN_FIND_HEADERS_VAR:=	H_LZMA H_LZMA_VERSION
BUILTIN_FIND_HEADERS.H_LZMA=	lzma.h
BUILTIN_FIND_HEADERS.H_LZMA_VERSION=lzma/version.h
BUILTIN_FIND_GREP.H_LZMA=	LZMA_

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.xz)
IS_BUILTIN.xz=		no
.  if empty(H_LZMA:M__nonexistent__) && empty(H_LZMA:M${LOCALBASE}/*)
IS_BUILTIN.xz=		yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xz

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xz) && \
    !empty(IS_BUILTIN.xz:M[yY][eE][sS])
BUILTIN_VERSION.xz!=							\
	${AWK} 'BEGIN { M = "0" }					\
		/\#define[ 	]+LZMA_VERSION_MAJOR/ { M = $$3 }	\
		/\#define[ 	]+LZMA_VERSION_MINOR/ { m = "."$$3 }	\
		/\#define[ 	]+LZMA_VERSION_PATCH/ { p = "."$$3 }	\
		/\#define[ 	]+LZMA_VERSION_STABILITY[ 	]+/ { 	\
			if (split($$3, ss, /_/) == 4 && ss[4] != "STABLE") { \
				s = tolower(ss[4])			\
			}						\
		}							\
		END { printf "%s%s%s%s\n", M, m, p, s}			\
	' ${H_LZMA_VERSION:Q}

BUILTIN_PKG.xz=		xz-${BUILTIN_VERSION.xz}
.endif
MAKEVARS+=	BUILTIN_PKG.xz

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xz)
.  if ${PREFER.xz} == "pkgsrc"
USE_BUILTIN.xz=	no
.  else
USE_BUILTIN.xz=	${IS_BUILTIN.xz}
.    if defined(BUILTIN_PKG.xz) && \
        !empty(IS_BUILTIN.xz:M[yY][eE][sS])
USE_BUILTIN.xz=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.xz}
.        if !empty(USE_BUILTIN.xz:M[yY][eE][sS])
USE_BUILTIN.xz!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xz:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
_INCOMPAT_XZ?=	# empty
.    for _pattern_ in ${_INCOMPAT_XZ} ${INCOMPAT_XZ}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.xz=	no
.      endif
.    endfor
.  endif  # PREFER.xz
.endif
MAKEVARS+=	USE_BUILTIN.xz

# if USE_XZ is defined, then force the use of a true xz
# implementation.
#
.if defined(USE_XZ)
.  if !empty(IS_BUILTIN.xz:M[nN][oO])
USE_BUILTIN.xz=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

CHECK_BUILTIN.xz?=	no
.if !empty(CHECK_BUILTIN.xz:M[nN][oO])

.  if !empty(USE_BUILTIN.xz:M[yY][eE][sS])
BUILDLINK_PREFIX.xz=	${H_LZMA:S/\/include\/lzma.h//}
BUILDLINK_FILES.xz+=	lib/pkgconfig/xz.pc
.  endif

.endif	# CHECK_BUILTIN.xz
