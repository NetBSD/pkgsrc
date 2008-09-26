# $NetBSD: builtin.mk,v 1.11.6.1 2008/09/26 19:59:46 cube Exp $

BUILTIN_PKG:=	freetype2

BUILTIN_FIND_FILES_VAR:=	H_FREETYPE2
BUILTIN_FIND_FILES.H_FREETYPE2=	${X11BASE}/include/freetype2/freetype/freetype.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.freetype2)
IS_BUILTIN.freetype2=	no
.  if empty(H_FREETYPE2:M__nonexistent__)
BUILTIN_IMAKE_CHECK:=	freetype2:BuildFreetype2Library
.    include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.freetype2=	${BUILTIN_IMAKE_CHECK.freetype2}
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.freetype2

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.freetype2) && \
    !empty(IS_BUILTIN.freetype2:M[yY][eE][sS]) && \
    empty(H_FREETYPE2:M__nonexistent__)
BUILTIN_VERSION.freetype2!=						\
	${AWK} 'BEGIN { p = ".0" }					\
		/\#define[ 	]*FREETYPE_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*FREETYPE_MINOR/ { m = "."$$3 }	\
		/\#define[ 	]*FREETYPE_PATCH/ { p = "."$$3 }	\
		END { printf "%s%s%s\n", M, m, p }'			\
		${H_FREETYPE2}
BUILTIN_PKG.freetype2=	freetype2-${BUILTIN_VERSION.freetype2}
.endif
MAKEVARS+=	BUILTIN_PKG.freetype2

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.freetype2)
.  if ${PREFER.freetype2} == "pkgsrc"
USE_BUILTIN.freetype2=	no
.  else
USE_BUILTIN.freetype2=	${IS_BUILTIN.freetype2}
.    if defined(BUILTIN_PKG.freetype2) && \
        !empty(IS_BUILTIN.freetype2:M[yY][eE][sS])
USE_BUILTIN.freetype2=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.freetype2}
.        if !empty(USE_BUILTIN.freetype2:M[yY][eE][sS])
USE_BUILTIN.freetype2!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.freetype2:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.freetype2
.endif
MAKEVARS+=	USE_BUILTIN.freetype2

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.freetype2?=	no
.if !empty(CHECK_BUILTIN.freetype2:M[nN][oO])

.  if !empty(USE_BUILTIN.freetype2:M[nN][oO])
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.3
.  endif

.endif	# CHECK_BUILTIN.freetype2
