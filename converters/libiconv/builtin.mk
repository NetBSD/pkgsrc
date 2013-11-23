# $NetBSD: builtin.mk,v 1.23 2013/11/23 10:58:46 obache Exp $

BUILTIN_PKG:=	iconv

BUILTIN_FIND_LIBS:=			iconv
BUILTIN_FIND_HEADERS_VAR:=		H_ICONV H_GLIBC_ICONV H_CITRUS_ICONV
BUILTIN_FIND_HEADERS.H_ICONV=		iconv.h
BUILTIN_FIND_GREP.H_ICONV=		GNU LIBICONV Library
BUILTIN_FIND_HEADERS.H_GLIBC_ICONV=	iconv.h
BUILTIN_FIND_GREP.H_GLIBC_ICONV=	This file is part of the GNU C Library
BUILTIN_FIND_HEADERS.H_CITRUS_ICONV=	iconv.h
BUILTIN_FIND_GREP.H_CITRUS_ICONV=	Copyright.*Citrus Project

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.iconv)
IS_BUILTIN.iconv=	no
.  if empty(H_ICONV:M__nonexistent__) && \
      empty(H_ICONV:M${LOCALBASE}/*) && \
      !empty(BUILTIN_LIB_FOUND.iconv:M[yY][eE][sS])
IS_BUILTIN.iconv=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.iconv

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.iconv) && \
    !empty(IS_BUILTIN.iconv:M[yY][eE][sS]) && \
    empty(H_ICONV:M__nonexistent__)
BUILTIN_VERSION.iconv!=							\
	${AWK} 'BEGIN { hex="0123456789abcdef" }			\
		/\#define[ 	]*_LIBICONV_VERSION[ 	]/ {		\
			M = 16 * (index(hex, tolower(substr($$3, 3, 1))) - 1); \
			M += index(hex, tolower(substr($$3, 4, 1))) - 1;\
			m = 16 * (index(hex, tolower(substr($$3, 5, 1))) - 1); \
			m += index(hex, tolower(substr($$3, 6, 1))) - 1;\
			printf "%d.%d\n", M, m;				\
			exit 0;						\
		}							\
	' ${H_ICONV}
#
# If the native GNU iconv is ABI version 1.9, then treat it the same
# as the latest version on the libiconv-1.9.x branch.
#
.  if ${BUILTIN_VERSION.iconv} == "1.9"
BUILTIN_VERSION.iconv=	1.9.2		# latest version on 1.9.x branch
.  endif
BUILTIN_PKG.iconv=	libiconv-${BUILTIN_VERSION.iconv}
.endif
MAKEVARS+=	BUILTIN_PKG.iconv

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.iconv)
.  if ${PREFER.iconv} == "pkgsrc"
USE_BUILTIN.iconv=	no
.  else
USE_BUILTIN.iconv=	${IS_BUILTIN.iconv}
.    if defined(BUILTIN_PKG.iconv) && \
        !empty(IS_BUILTIN.iconv:M[yY][eE][sS])
USE_BUILTIN.iconv=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.iconv}
.        if !empty(USE_BUILTIN.iconv:M[yY][eE][sS])
USE_BUILTIN.iconv!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.iconv:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
# XXX
# XXX By default, assume that the native iconv implementation is good
# XXX enough to replace GNU libiconv if it is part of glibc (the GNU C
# XXX Library).
# XXX
.    if empty(H_GLIBC_ICONV:M__nonexistent__) && \
	empty(H_GLIBC_ICONV:M${LOCALBASE}/*) && \
	!empty(BUILTIN_LIB_FOUND.iconv:M[nN][oO])
USE_BUILTIN.iconv=	yes
H_ICONV=		${H_GLIBC_ICONV}
.    endif
# XXX
# XXX By default, assume that the Citrus project iconv implementation
# XXX (if it exists) is good enough to replace GNU libiconv.
# XXX
.    if empty(H_CITRUS_ICONV:M__nonexistent__) && \
	empty(H_CITRUS_ICONV:M${LOCALBASE}/*) && \
	!empty(BUILTIN_LIB_FOUND.iconv:M[nN][oO])
USE_BUILTIN.iconv=	yes
H_ICONV=		${H_CITRUS_ICONV}
.    endif
#
# Some platforms don't have an iconv implementation that can replace
# GNU libiconv.
#
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
.    for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.iconv=	no
.      endif
.    endfor
.  endif  # PREFER.iconv
.endif
MAKEVARS+=	USE_BUILTIN.iconv

# If USE_GNU_ICONV is defined, then force the use of a GNU libiconv
# implementation.
#
.if defined(USE_GNU_ICONV)
.  if !empty(IS_BUILTIN.iconv:M[nN][oO])
USE_BUILTIN.iconv=	no
.  endif
.endif

# Define BUILTIN_LIBNAME.iconv to be the base name of the built-in
# iconv library.
#
.if !empty(BUILTIN_LIB_FOUND.iconv:M[yY][eE][sS])
BUILTIN_LIBNAME.iconv=	iconv
.else
BUILTIN_LIBNAME.iconv=	# empty (part of the C library)
.endif

# ICONV_TYPE is either "gnu" or "native" depending on which iconv
# implementation is used.
#
.if !defined(ICONV_TYPE)
ICONV_TYPE?=	gnu
.  if !empty(USE_BUILTIN.iconv:M[yY][eE][sS]) && \
      !empty(IS_BUILTIN.iconv:M[nN][oO])
ICONV_TYPE=	native
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.iconv?=	no
.if !empty(CHECK_BUILTIN.iconv:M[nN][oO])

.  if !empty(USE_BUILTIN.iconv:M[yY][eE][sS])
BUILDLINK_LIBNAME.iconv=	${BUILTIN_LIBNAME.iconv}
.    if empty(BUILTIN_LIBNAME.iconv)
BUILDLINK_TRANSFORM+=		rm:-liconv
.    endif
.  endif

.  if defined(GNU_CONFIGURE)
.    if !empty(USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
.    endif
.  endif

.endif	# CHECK_BUILTIN.iconv
