# $NetBSD: builtin.mk,v 1.16.8.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	Xft2

BUILTIN_FIND_FILES_VAR:=	H_XFT2
BUILTIN_FIND_FILES.H_XFT2=	${X11BASE}/include/X11/Xft/Xft.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.Xft2)
IS_BUILTIN.Xft2=	no
.  if empty(H_XFT2:M__nonexistent__)
BUILTIN_IMAKE_CHECK:=	Xft2:BuildXftLibrary
.    include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.Xft2=	${BUILTIN_IMAKE_CHECK.Xft2}
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.Xft2

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.Xft2) && \
    !empty(IS_BUILTIN.Xft2:M[yY][eE][sS]) && \
    empty(H_XFT2:M__nonexistent__)
#
# Extract the version number from the header file, but if it's not
# there, then pretend it's from version 2.0.
#
BUILTIN_VERSION.Xft2!=							\
	${AWK} 'BEGIN { M = 2; m = ".0"; r = "" }			\
		/\#define[ 	]*XFT_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*XFT_MINOR/ { m = "."$$3 }		\
		/\#define[ 	]*XFT_REVISION/ { r = "."$$3 }		\
		END { printf "%s%s%s\n", M, m, r }'			\
		${H_XFT2}
BUILTIN_PKG.Xft2=	Xft2-${BUILTIN_VERSION.Xft2}
.endif
MAKEVARS+=	BUILTIN_PKG.Xft2

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
#
# These are dependencies of Xft2.  If we need to use the pkgsrc
# versions of any of these, then also use the pkgsrc version of
# Xft2.
#
.if defined(USE_BUILTIN.Xrender) && !empty(USE_BUILTIN.Xrender:M[nN][oO])
USE_BUILTIN.Xft2=	no
.endif
.if defined(USE_BUILTIN.fontconfig) && !empty(USE_BUILTIN.fontconfig:M[nN][oO])
USE_BUILTIN.Xft2=	no
.endif

.if !defined(USE_BUILTIN.Xft2)
.  if ${PREFER.Xft2} == "pkgsrc"
USE_BUILTIN.Xft2=	no
.  else
USE_BUILTIN.Xft2=	${IS_BUILTIN.Xft2}
.    if defined(BUILTIN_PKG.Xft2) && \
        !empty(IS_BUILTIN.Xft2:M[yY][eE][sS])
USE_BUILTIN.Xft2=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.Xft2}
.        if !empty(USE_BUILTIN.Xft2:M[yY][eE][sS])
USE_BUILTIN.Xft2!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.Xft2:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.Xft2
.endif
MAKEVARS+=	USE_BUILTIN.Xft2

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.Xft2?=	no
.if !empty(CHECK_BUILTIN.Xft2:M[nN][oO])

.  if !empty(USE_BUILTIN.Xft2:M[nN][oO])
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1nb2
.  endif

.endif	# CHECK_BUILTIN.Xft2
