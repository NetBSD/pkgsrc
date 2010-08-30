# $NetBSD: builtin.mk,v 1.2 2010/08/30 17:27:11 drochner Exp $

BUILTIN_PKG:=	librfuncs
.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.include "../../mk/bsd.fast.prefs.mk"
# NetBSD-5 and later has all these functions in libc
# other OSes: append your patterns here
_RFUNCS_IN_LIBC= NetBSD-[5-9].*-*
.for _pl in ${_RFUNCS_IN_LIBC}
.  if !empty(MACHINE_PLATFORM:M${_pl})
IS_BUILTIN.librfuncs=	yes
.  endif
.endfor
IS_BUILTIN.librfuncs?=	no
MAKEVARS+=	IS_BUILTIN.librfuncs

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.librfuncs)
.  if ${PREFER.librfuncs} == "pkgsrc"
USE_BUILTIN.librfuncs=	no
.  else
USE_BUILTIN.librfuncs=	${IS_BUILTIN.librfuncs}
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.librfuncs

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.librfuncs?=	no
.if !empty(CHECK_BUILTIN.librfuncs:M[nN][oO])
.  if !empty(USE_BUILTIN.librfuncs:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=		rm:-lrfuncs
.  else
BUILDLINK_LDFLAGS.librfuncs+=	-lrfuncs
.  endif
.endif	# CHECK_BUILTIN.librfuncs
