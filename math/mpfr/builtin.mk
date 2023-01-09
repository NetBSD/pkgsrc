# $NetBSD: builtin.mk,v 1.8 2023/01/09 13:25:11 wiz Exp $

BUILTIN_PKG:=	mpfr

BUILTIN_FIND_HEADERS_VAR:=	H_MPFR
BUILTIN_FIND_HEADERS.H_MPFR=	mpfr.h mpfr/mpfr.h

BUILTIN_VERSION_SCRIPT.mpfr=	${AWK} \
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
MAKEVARS+=		IS_BUILTIN.mpfr

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.mpfr) && \
    ${IS_BUILTIN.mpfr:tl} == yes && \
    empty(H_MPFR:M__nonexistent__)
BUILTIN_VERSION.mpfr!=	${BUILTIN_VERSION_SCRIPT.mpfr} ${H_MPFR}
BUILTIN_PKG.mpfr=	mpfr-${BUILTIN_VERSION.mpfr}
.endif
MAKEVARS+=		BUILTIN_PKG.mpfr

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.mpfr)
.  if ${PREFER.mpfr} == "pkgsrc"
USE_BUILTIN.mpfr=	no
.  else
USE_BUILTIN.mpfr=	${IS_BUILTIN.mpfr}
.    if defined(BUILTIN_PKG.mpfr) && ${IS_BUILTIN.mpfr:tl} == yes
USE_BUILTIN.mpfr=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.mpfr}
.        if ${USE_BUILTIN.mpfr:tl} == yes
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
MAKEVARS+=		USE_BUILTIN.mpfr

CHECK_BUILTIN.mpfr?=	no
.if ${CHECK_BUILTIN.mpfr:tl} == no
.  if ${USE_BUILTIN.mpfr:tl} == yes
MPFR_INCLUDE=		${H_MPFR:H}
BUILDLINK_INCDIRS.mpfr=	${MPFR_INCLUDE}
BUILDLINK_LIBDIRS.mpfr=	lib${LIBABISUFFIX}
CPPFLAGS+=		-I${MPFR_INCLUDE}
CFLAGS+=		-I${MPFR_INCLUDE}
.  endif
.endif # CHECK_BUILTIN.mpfr
