# $NetBSD: builtin.mk,v 1.4.8.1 2007/05/31 11:26:46 salo Exp $

BUILTIN_PKG:=	binutils
.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
# XXX Assume that the base OS always provides a built-in binutils.
IS_BUILTIN.binutils?=	yes

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.binutils)
.  if ${PREFER.binutils} == "pkgsrc"
USE_BUILTIN.binutils=	no
.  else
USE_BUILTIN.binutils=	${IS_BUILTIN.binutils}
.    if defined(BUILTIN_PKG.binutils) && \
        !empty(IS_BUILTIN.binutils:M[yY][eE][sS])
USE_BUILTIN.binutils=	yes
.      for dep in ${BUILDLINK_API_DEPENDS.binutils}
.        if !empty(USE_BUILTIN.binutils:M[yY][eE][sS])
USE_BUILTIN.binutils!=							\
	if ${PKG_ADMIN} pmatch ${dep:Q} ${BUILTIN_PKG.binutils:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
#
# Some platforms don't have a toolchain that can replace pkgsrc binutils.
#
_INCOMPAT_BINUTILS=	NetBSD-0.*-* NetBSD-1.[01234]*-*		\
			NetBSD-1.5.*-* NetBSD-1.5[A-X]-*
.    for pattern in ${_INCOMPAT_BINUTILS} ${INCOMPAT_BINUTILS}
.      if !empty(MACHINE_PLATFORM:M${pattern})
USE_BUILTIN.binutils=	no
.      endif
.    endfor
.  endif  # PREFER.binutils
.endif
MAKEVARS+=	USE_BUILTIN.binutils

# if USE_BINUTILS is defined, then force the use of a true binutils
# implementation.
#
.if defined(USE_BINUTILS)
.  if !empty(IS_BUILTIN.binutils:M[nN][oO])
USE_BUILTIN.binutils=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.binutils?=	no
.if !empty(CHECK_BUILTIN.binutils:M[nN][oO])

.  if !empty(USE_BUILTIN.binutils:M[nN][oO])
AR=	${BUILDLINK_PREFIX.binutils}/bin/ar
AS=	${BUILDLINK_PREFIX.binutils}/bin/as
LD=	${BUILDLINK_PREFIX.binutils}/bin/ld
NM=	${BUILDLINK_PREFIX.binutils}/bin/nm
RANLIB=	${BUILDLINK_PREFIX.binutils}/bin/ranlib
.  endif

.endif	# CHECK_BUILTIN.binutils
