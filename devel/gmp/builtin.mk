# $NetBSD: builtin.mk,v 1.11 2020/11/16 13:12:41 wiz Exp $

BUILTIN_PKG:=	gmp

BUILTIN_FIND_HEADERS_VAR:=	H_GMP
BUILTIN_FIND_HEADERS.H_GMP=	gmp.h gmp/gmp.h

BUILTIN_VERSION_SCRIPT.gmp=	${AWK} \
				'/\#define[ \t]*__GNU_MP_VERSION[ \t]/ { major = $$3; } \
				/\#define[ \t]*__GNU_MP_VERSION_MINOR[ \t]/ { minor = $$3; } \
				/\#define[ \t]*__GNU_MP_VERSION_PATCHLEVEL[ \t]/ { patch = $$3; } \
				END { if (major!="" && minor!="" && patch!="") \
				print major "." minor "." patch; else print ""; }'

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.gmp)
IS_BUILTIN.gmp=	no
.  if empty(H_GMP:M__nonexistent__) && empty(H_GMP:M${LOCALBASE}/*)
IS_BUILTIN.gmp=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.gmp

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.gmp) && \
    !empty(IS_BUILTIN.gmp:M[yY][eE][sS]) && \
    empty(H_GMP:M__nonexistent__)
BUILTIN_VERSION.gmp!=	${BUILTIN_VERSION_SCRIPT.gmp} ${H_GMP}
BUILTIN_PKG.gmp=	gmp-${BUILTIN_VERSION.gmp}
.endif
MAKEVARS+=		BUILTIN_PKG.gmp

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.gmp)
.  if ${PREFER.gmp} == "pkgsrc"
USE_BUILTIN.gmp=	no
.  else
USE_BUILTIN.gmp=	${IS_BUILTIN.gmp}
.    if defined(BUILTIN_PKG.gmp) && !empty(IS_BUILTIN.gmp:M[yY][eE][sS])
USE_BUILTIN.gmp=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.gmp}
.        if !empty(USE_BUILTIN.gmp:M[yY][eE][sS])
USE_BUILTIN.gmp!=	\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.gmp:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.gmp
.endif
MAKEVARS+=		USE_BUILTIN.gmp

CHECK_BUILTIN.gmp?=	no
.if !empty(CHECK_BUILTIN.gmp:M[Nn][Oo])
.  if !empty(USE_BUILTIN.gmp:M[Yy][Ee][Ss])
GMP_INCLUDE=		${H_GMP:H}
BUILDLINK_INCDIRS.gmp=	${GMP_INCLUDE}
BUILDLINK_LIBDIRS.gmp=	lib${LIBABISUFFIX}
CPPFLAGS+=		-I${GMP_INCLUDE}
CFLAGS+=		-I${GMP_INCLUDE}
.  endif
.endif # CHECK_BUILTIN.gmp
