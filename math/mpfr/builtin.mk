# $NetBSD: builtin.mk,v 1.4 2019/05/31 08:36:12 dholland Exp $

BUILTIN_PKG:=	mpfr

BUILTIN_FIND_HEADERS_VAR:=	H_MPFR
BUILTIN_FIND_HEADERS.H_MPFR=	mpfr.h mpfr/mpfr.h

BUILTIN_VERSION_SCRIPT.mpfr= ${AWK} \
	'/\#define[ \t]*MPFR_VERSION_STRING[ \t]/ { \
	v = substr($$3, 2, length($$3)-2) } \
	END { gsub("-p",".",v); print v }'

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.mpfr)
IS_BUILTIN.mpfr=	no
.  if empty(H_MPFR:M__nonexistent__) && empty(H_MPFR:M${LOCALBASE}/*)
IS_BUILTIN.mpfr=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.mpfr

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.mpfr) && \
    !empty(IS_BUILTIN.mpfr:M[yY][eE][sS]) && \
    empty(H_MPFR:M__nonexistent__)
BUILTIN_VERSION.mpfr!=	${BUILTIN_VERSION_SCRIPT.mpfr} ${H_MPFR}
BUILTIN_PKG.mpfr=	mpfr-${BUILTIN_VERSION.mpfr}
.endif
MAKEVARS+=	BUILTIN_PKG.mpfr

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.mpfr)
.  if ${PREFER.mpfr} == "pkgsrc"
USE_BUILTIN.mpfr=	no
.  else
USE_BUILTIN.mpfr=	${IS_BUILTIN.mpfr}
.    if defined(BUILTIN_PKG.mpfr) && !empty(IS_BUILTIN.mpfr:M[yY][eE][sS])
USE_BUILTIN.mpfr=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.mpfr}
.        if !empty(USE_BUILTIN.mpfr:M[yY][eE][sS])
USE_BUILTIN.mpfr!=	\
        if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.mpfr:Q}; then	\
		${ECHO} yes;						\
        else								\
		${ECHO} no;						\
        fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.mpfr
.endif
MAKEVARS+=	USE_BUILTIN.mpfr

CHECK_BUILTIN.mpfr?=	no
.if !empty(CHECK_BUILTIN.mpfr:M[Nn][Oo])
.  if !empty(USE_BUILTIN.mpfr:M[Yy][Ee][Ss])
MPFR_INCLUDE=		${H_MPFR:H}
CONFIGURE_ARGS+=	--with-mpfr-include=${MPFR_INCLUDE}
BUILDLINK_INCDIRS.mpfr=	${MPFR_INCLUDE}
CONFIGURE_ARGS+=	--with-mpfr-lib=${BUILDLINK_PREFIX.mpfr}/lib${LIBABISUFFIX}
BUILDLINK_LIBDIRS.mpfr=	lib${LIBABISUFFIX}
CPPFLAGS+=		-I${MPFR_INCLUDE}
CFLAGS+=		-I${MPFR_INCLUDE}
.  endif
.endif # CHECK_BUILTIN.mpfr
